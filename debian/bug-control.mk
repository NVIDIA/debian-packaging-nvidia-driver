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
	$(nvidia)-alternative
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
	libgl1-nvidia-glx-ia32-any
	libgl1-nvidia-glx-ia32
	libgl1-nvidia-legacy-173xx-glx-ia32
	libgl1-nvidia-legacy-96xx-glx-ia32
	libgl1-nvidia-alternatives-ia32
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
	xserver-xorg-legacy
	linux-headers
	bumblebee
	bumblebee-nvidia
	libdrm-nouveau1
	libdrm-nouveau1a
	libdrm-nouveau2
	xserver-xorg-video-nouveau
	ia32-libs
	make
	libopencl1
	opencl-icd
endef

