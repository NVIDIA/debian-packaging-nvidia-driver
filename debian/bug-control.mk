debian/bug-control: debian/bug-control.mk debian/rules debian/rules.defs
	$(RM) $@
	echo "report-with: $(foreach x,$(REPORT_WITH),$(strip $x))" > $@
	echo "" >> $@
	echo "package-status: $(foreach x,$(PACKAGE_STATUS),$(strip $x))" >> $@


define REPORT_WITH
	$(nvidia)-driver
	nvidia-glx$(legacy)
	libgl1-$(nvidia)-glx
	xserver-xorg-video-$(nvidia)
	$(NVIDIA_ALTERNATIVE)
	$(nvidia)-kernel-dkms
	$(nvidia)-kernel-source
	glx-alternative-nvidia
	xserver-xorg-video-intel
endef

define PACKAGE_STATUS
	$(nvidia)-driver
	nvidia-glx$(legacy)
	$(nvidia)-kernel-dkms
	$(nvidia)-kernel-source
	nvidia-kernel-support-any
	nvidia-glx-any
	libgl1-nvidia-glx-any
	xserver-xorg-video-nvidia-any
	libcuda1
	libcuda1-any
	nvidia-settings
	nvidia-xconfig
	nvidia-support
	nvidia-kernel-common
	nvidia-modprobe
	xserver-xorg
	xserver-xorg-core
	linux-headers
	bumblebee
	bumblebee-nvidia
	libdrm-nouveau1
	libdrm-nouveau1a
	libdrm-nouveau2
	xserver-xorg-video-nouveau
	make
endef

