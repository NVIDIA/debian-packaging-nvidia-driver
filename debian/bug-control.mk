multiarchify	 = $(if $(filter %:any,$1),$(foreach a,$(ARCH_LIST),$(1:any=$a)),$1)

debian/bug-control: debian/bug-control.mk debian/rules debian/rules.defs
	$(RM) $@
	echo "report-with: $(foreach x,$(REPORT_WITH),$(call multiarchify,$(strip $x)))" > $@
	echo "" >> $@
	echo "package-status: $(foreach x,$(PACKAGE_STATUS),$(strip $x))" >> $@


define REPORT_WITH
	$(nvidia)-driver
	$(nvidia)-driver-libs:any
	$(nvidia)-driver-libs-nonglvnd:any
	nvidia-glx$(-variant)
	libgl1-$(nvidia)-glx:any
	libgl1-glvnd-$(nvidia)-glx:any
	xserver-xorg-video-$(nvidia)
	$(nvidia)-alternative
	$(nvidia)-kernel-dkms
	$(nvidia)-kernel-source
	glx-alternative-nvidia
	xserver-xorg-video-intel
endef

define PACKAGE_STATUS
	$(nvidia)-driver
	nvidia-glx$(-variant)
	$(nvidia)-kernel-dkms
	$(nvidia)-kernel-source
	nvidia-kernel-support-any
	nvidia-driver-any
	nvidia-glx-any
	nvidia-driver-libs-any
	libgl1-nvidia-glx-any
	xserver-xorg-video-nvidia-any
	nvidia-vulkan-icd-any
	libnvidia-cfg1-any
	libcuda1
	libcuda1-any
	libcuda.so.1
	libnvidia-ml.so.1
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
	primus
	primus-libs
	primus-nvidia
	primus-vk
	primus-vk-nvidia
	libprimus-vk1
	nvidia-primus-vk-wrapper
	libdrm-nouveau1
	libdrm-nouveau1a
	libdrm-nouveau2
	xserver-xorg-video-nouveau
	make
	ccache
	libopencl1
	opencl-icd
	libvulkan1
	vulkan-icd
	libglvnd0
	libglx0
	libopencl0
	libgl1
	libegl1
	libgles1
	libgles2
endef

