#!/usr/bin/make -f

# if you need to redefine these
KSRC:=$(KSRC)
KVERS:=${KVERS}


# redefine the directory for kbuild to fine the makefile.
KBUILD_PARAMS := "-C $(KSRC) SUBDIRS=$(CURDIR)"

    
#### COMPILER DETECTION ####

ifeq ($(origin CC),default)
ifneq "$(wildcard $(KSRC)/include/linux/compile.h)" ""
CC = gcc-$(shell grep LINUX_COMPILER $(KSRC)/include/linux/compile.h | sed 's/.*[gcc|GCC].* \([0-9]\.[0-9]\+\).*/\1/')
else
CC = gcc
endif
endif

ifeq ($(CC),gcc-2.7)
CC = gcc272
endif

# determine gcc versions used (kernel, nvidia.o)
module_cc:=$(shell $(CC) -v 2>&1 | tail -1) 
version="^Linux version [^(]* (.*@.*) (\(gcc.*\)) .*"
kernel_cc:=$(shell cat /proc/version | sed "s/"$(version)"/\1/")

kernel_arch:=$(shell uname -m)
module_cc:=$(shell echo "$(module_cc)" | sed 's/.* \([0-9.]*\.[0-9]\).*/\1/')
kernel_cc:=$(shell echo "$(kernel_cc)" | sed 's/.* \([0-9.]*\.[0-9]\).*/\1/')

baseepoch=$(shell expr $(KDREV) : '\([0-9]*\):.*' 2>/dev/null )
ifneq ($(baseepoch),)
      EPOCH=$(baseepoch):
endif
REV=$(shell expr $(KDREV) : '[0-9]*:\(.*\)' 2>/dev/null)
ifeq ($(REV),)
     REV=$(KDREV)
endif
VERSION=$(shell dpkg-parsechangelog | grep ^Version: | cut -d ' ' -f 2)
ifeq ($(REV),)
PKG_VERSION=$(EPOCH)$(VERSION)
else
PKG_VERSION=$(EPOCH)$(VERSION)+$(REV)
endif



CHFILE=$(CURDIR)/../../nvidia-kernel-$(KVERS)_$(PKG_VERSION)_$(ARCH).changes


KERNEL_VERSION_CODE = $(shell cat $(KSRC)/include/linux/version.h | grep LINUX_VERSION_CODE  | cut -d " " -f 3)
DESIRED_VERSION=132608
# 2 << 16 + 6 << 8 + 0 
VERSION_EXPR = $(shell test $(KERNEL_VERSION_CODE) -ge $(DESIRED_VERSION) ; echo $$? )

ifeq ($(VERSION_EXPR),0) 
  PATCHLEVEL=6
else
  PATCHLEVEL=4
endif  

# If 2.6.10-rc3-bk13 or greater, use minion.de kernel patches
#DESIRED_VERSION=132618
#VERSION_EXPR2 = $(shell test $(KERNEL_VERSION_CODE) -ge $(DESIRED_VERSION) ; echo $$? )

#ifeq ($(VERSION_EXPR2),0)
#  NV_PATCH_MINION=1
#else
#  NV_PATCH_MINION=0
#endif

%.Makefile :
	# select which makefile to use.
	rm -f $(CURDIR)/Makefile || true
	if [ $(PATCHLEVEL) = 6  ]; then \
	     ln -s Makefile.kbuild Makefile ; \
	fi
	
	if [  $(PATCHLEVEL) = 4  ]; then \
	     ln -s Makefile.nvidia Makefile ; \
	fi




.PHONY: configure configure-stamp
configure: configure-stamp
configure-stamp: config.Makefile

		 
	
	if ! $(CC) -v 2> /dev/null  ; then \
	   echo "Compiler $(CC) does not exist on the system" ; \
	   exit 1; \
	fi   
	if [ -f $(CURDIR)/debian/control.template ]; then \
		cp  $(CURDIR)/debian/control.template $(CURDIR)/debian/control; \
	fi
	if [ "$(kernel_arch)" = "x86_64" ]; then \
		cp $(CURDIR)/nv-kernel.o.x86_64 $(CURDIR)/nv-kernel.o ; \
	fi
	#patch for XEN
	patch -p3 < $(CURDIR)/debian/patches/xen.patch
	
	touch configure-stamp


							
