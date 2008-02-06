#!/usr/bin/make -f
# Makefile for building prebuilt nvidia kernel modules
include $(M)/debian/conf.mk

binary:
	echo "binary";
       
modules:
	echo "modules";


.PHONY: build build-stamp
build: configure-stamp build-stamp
build-stamp:


	touch $(M)/$(dirname)/gcc-check
	touch $(M)/$(dirname)/cc-sanity-check

	## Main Make ##
	IGNORE_CC_MISMATCH=1 CC="$(CC)" $(MAKE) -C $(M)/$(dirname) -f Makefile SYSSRC=$(KSRC)  $(KPKG_EXTRAV_ARG) KBUILD_PARAMS=$(KBUILD_PARAMS) module;

	touch build-stamp


.PHONY: install
install: build
	dh_testdir
	dh_testroot
	dh_clean -k

	sed 's/#KVERS#/$(KVERS)/g' debian/control.template > $(M)/debian/control
	sed 's/#KVERS#/$(KVERS)/g' debian/dirs.template > $(M)/debian/dirs
	sed 's/#KVERS#/$(KVERS)/g' debian/override.template > $(M)/debian/override

	dh_installdirs


	install -m 0644 $(CURDIR)/debian/override $(M)/debian/nvidia-kernel-$(KVERS)/usr/share/lintian/overrides/nvidia-kernel-$(KVERS)
	if [ "$(PATCHLEVEL)" = "6" ] ; then \
	   install -m 0644 $(CURDIR)/$(dirname)/nvidia.ko $(M)/debian/nvidia-kernel-$(KVERS)/lib/modules/$(KVERS)/nvidia/nvidia.ko ; \
	else \
	   install -m 0644 $(CURDIR)/$(dirname)/nvidia.o $(M)/debian/nvidia-kernel-$(KVERS)/lib/modules/$(KVERS)/nvidia/nvidia.o ;\
	fi

.PHONY: clean
clean: clean.Makefile 
	if [ -f $(CURDIR)/debian/control.template ]; then \
		cp  $(CURDIR)/debian/control.template $(CURDIR)/debian/control; \
	fi

	rm -f build-stamp configure-stamp


	$(MAKE) clean SYSSRC=$(KSRC) -C $(M)/$(dirname) -f Makefile $(KPKG_EXTRAV_ARG)
        
	rm -f $(M)/$(dirname)/Makefile || true; 	
	-rm $(M)/$(dirname)/gcc-check
	-rm $(M)/$(dirname)/cc-sanity-check
	
	-dh_clean

	-rm $(M)/debian/control
	-rm $(M)/debian/dirs
	-rm $(M)/debian/override
