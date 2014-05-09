#
# By default, the build is done against the running linux kernel source.
# To build against a different kernel source tree, set SYSSRC:
#
#    make SYSSRC=/path/to/kernel/source

ifneq ($(KERNELRELEASE),)
$(error Running inside Kbuild should not use the Makefile)
endif

ifdef SYSSRC
 KERNEL_SOURCES	 = $(SYSSRC)
else
 KERNEL_UNAME	:= $(shell uname -r)
 KERNEL_SOURCES	 = /lib/modules/$(KERNEL_UNAME)/build
endif

ifndef NV_VERBOSE
 ifneq ($(strip $(QUIET)),1)
 NV_VERBOSE=1
 else
 NV_VERBOSE=0
 endif
endif

KBUILD_PARAMS += KBUILD_VERBOSE=$(NV_VERBOSE)
KBUILD_PARAMS += -C $(KERNEL_SOURCES) M=$(CURDIR)


default: modules
.PHONY: default

# hand over to kbuild
%::
	$(MAKE) $(KBUILD_PARAMS) $@
