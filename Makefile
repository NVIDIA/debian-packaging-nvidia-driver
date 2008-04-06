#!/usr/bin/make -f
# Makefile for building prebuilt nvidia kernel modules


KVERS = $(KERNELVERSION)
KSRC = $(CURDIR)
include $(M)/debian/conf.mk



all:


	touch $(M)/$(dirname)/gcc-check
	touch $(M)/$(dirname)/cc-sanity-check

	## Main Make ##
	IGNORE_CC_MISMATCH=1 CC="$(CC)" $(MAKE) -C $(M)/$(dirname) -f Makefile SYSSRC=$(KSRC)  $(KPKG_EXTRAV_ARG) KBUILD_PARAMS=$(KBUILD_PARAMS) module;

	touch build-stamp

modules_install: $(M)/$(dirname)/nvidia.ko
		



clean:
	$(MAKE) clean SYSSRC=$(KSRC) -C $(M)/$(dirname) -f Makefile $(KPKG_EXTRAV_ARG)
        
	rm -f $(M)/$(dirname)/Makefile || true; 	
	-rm $(M)/$(dirname)/gcc-check
	-rm $(M)/$(dirname)/cc-sanity-check
	
