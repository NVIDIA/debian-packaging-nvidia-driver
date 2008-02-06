#!/usr/bin/make -f
# Makefile for building prebuilt nvidia kernel modules
include $(M)/debian/conf.mk
IGNORE_CC_MISMATCH=1 CC="$(CC)" $(MAKE) -C $(M)/$(dirname) -f Makefile SYSSRC=$(KSRC)  $(KPKG_EXTRAV_ARG) KBUILD_PARAMS=$(KBUILD_PARAMS) module
