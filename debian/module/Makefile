# Makefile -- For the nvidia module

#
# By default, the build is done against the running linux kernel source.
# To build against a different kernel source tree, set SYSSRC:
#
#    make SYSSRC=/path/to/kernel/source

SHELL=/bin/sh

# avoid ld.gold, see #626279
LD=ld.bfd

.SUFFIXES:

ifndef SYSSRC
RUNNING_REL := $(shell uname -r)
SYSSRC := $(firstword $(wildcard /lib/modules/$(RUNNING_REL)/source /lib/modules/$(RUNNING_REL)/build))
endif

ifndef O
O := $(shell if [ -e /lib/modules/$(RUNNING_REL)/build ]; then \
		 echo /lib/modules/$(RUNNING_REL)/build; \
		 else echo ""; fi)
#O := $(LINUXDIR)
endif

ifdef ARCH
MACHINE := $(ARCH)
else
MACHINE := $(shell uname -m)
endif

# Modules for all architectures
MODULE_LIST := nvidia.o

CLEANFILES = *.o *.ko .depend .*.flags .*.d .*.cmd *.mod.c .tmp_versions

# VERSION is not defined from the initial invocation.  It is defined when
# this Makefile is invoked from the kernel's root Makefile.

ifndef VERSION

CLEANCONFIG := $(shell if cmp -s $(LINUXDIR)/.config .config; then echo y; fi)
ifeq ($(CLEANCONFIG),y)
CLEANFILES += $(LINUXDIR)/.config .config $(LINUXDIR)/tmp_include_depends
endif

all: modules

modules: includes
	+$(MAKE) -C $(SYSSRC) M=$(PWD) modules

clean cleandir:
	rm -rf $(CLEANFILES)

$(MODULE_LIST)::
	make modules

install:
	$(MAKE) -C $(SYSSRC) M=$(PWD) modules_install

else

# Check for kernel versions that we don't support.

# This needs to go before all other include paths.
CC += -I$(M)

ifeq ($(CONFIG_X86_64),y)
NVARCH = .x86_64
else
NVARCH = .i386
endif

include $(M)/Makefile.kbuild

endif

.PHONY: includes
