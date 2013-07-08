#
# By default, the build is done against the running linux kernel source.
# To build against a different kernel source tree, set SYSSRC:
#
#    make SYSSRC=/path/to/kernel/source

ifneq ($(KERNELRELEASE),)
$(error Running inside Kbuild should not use the Makefile)
endif

ifndef SYSSRC
RUNNING_REL := $(shell uname -r)
SYSSRC := /lib/modules/$(RUNNING_REL)/build
endif

default: modules
.PHONY: default

# hand over to kbuild
%::
	$(MAKE) -C $(SYSSRC) M=$(PWD) $@
