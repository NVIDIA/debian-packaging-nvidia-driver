# debian packaging nvidia driver

[![License](https://img.shields.io/badge/License-GPL%202.0-blue.svg)](https://opensource.org/licenses/GPL-2.0)
[![Contributing](https://img.shields.io/badge/Contributing-Developer%20Certificate%20of%20Origin-violet)](https://developercertificate.org)

## Overview

Packaging templates for `Debian` based Linux distros to build NVIDIA driver packages.

The `main` branch contains this README. The `control` and `.install` files can be found in the appropriate [buster](../../tree/buster) and [bullseye](../../tree/bullseye) branches.

## Table of Contents

- [Overview](#Overview)
- [Deliverables](#Deliverables)
- [Prerequisites](#Prerequisites)
  * [Clone this git repository](#Clone-this-git-repository)
  * [Download a NVIDIA driver runfile](#Download-a-NVIDIA-driver-runfile)
  * [Install build dependencies](#Install-build-dependencies)
<!--
- [Related](#Related)
  * [NVIDIA modprobe](#NVIDIA-modprobe)
  * [NVIDIA settings](#NVIDIA-settings)
-->
- [See also](#See-also)
  * [Ubuntu driver](#Ubuntu-driver)
  * [RHEL driver](#RHEL-driver)
  * [SUSE driver](#SUSE-driver)
- [Contributing](#Contributing)


## Deliverables

This repo contains the template files used to build the following **DEB** packages:

> *note:* `flavor` is the first `.` delimited field in the driver version, ex: `470` in `470.108.03`

* **Debian 10** or **Debian 11**
 ```shell
 - libcuda1
 - libcudadebugger1
 - libegl1-nvidia
 - libegl-nvidia0
 - libgl1-nvidia-glvnd-glx
 - libgles-nvidia1
 - libgles-nvidia2
 - libglx-nvidia0
 - libnvcuvid1
 - libnvidia-allocator1
 - libnvidia-api1
 - libnvidia-cfg1
 - libnvidia-compiler
 - libnvidia-eglcore
 - libnvidia-encode1
 - libnvidia-fbc1
 - libnvidia-glcore
 - libnvidia-glvkspirv
 - libnvidia-ml1
 - libnvidia-nvvm4
 - libnvidia-opticalflow1
 - libnvidia-ptxjitcompiler1
 - libnvidia-rtcore
 - libnvidia-wayland-client
 - libnvoptix1
 - nvidia-alternative
 - nvidia-cuda-mps
 - nvidia-detect
 - nvidia-driver
 - nvidia-driver-bin
 - nvidia-driver-libs
 - nvidia-egl-common
 - nvidia-egl-icd
 - nvidia-kernel-dkms
 - nvidia-kernel-source
 - nvidia-kernel-support
 - nvidia-legacy-check
 - nvidia-libopencl1
 - nvidia-nonglvnd-vulkan-common
 - nvidia-opencl-common
 - nvidia-opencl-icd
 - nvidia-smi
 - nvidia-vdpau-driver
 - nvidia-vulkan-common
 - nvidia-vulkan-icd
 - xserver-xorg-video-nvidia
 ```

## Prerequisites

### Clone this git repository:

Supported branches: `buster` & `bullseye`

```shell
git clone -b ${branch} https://github.com/NVIDIA/debian-packaging-nvidia-driver
> ex: git clone -b bullseye https://github.com/NVIDIA/debian-packaging-nvidia-driver
```

### Download a NVIDIA driver runfile:

* **TRD** location: [https://us.download.nvidia.com/tesla/](https://us.download.nvidia.com/tesla/) (not browsable)

  *ex:* [https://us.download.nvidia.com/tesla/470.108.03/NVIDIA-Linux-x86_64-470.108.03.run](https://us.download.nvidia.com/tesla/470.108.03/NVIDIA-Linux-x86_64-470.108.03.run)

* **UDA** location: [https://download.nvidia.com/XFree86/Linux-x86_64/](https://download.nvidia.com/XFree86/Linux-x86_64/)

  *ex:* [https://us.download.nvidia.com/XFree86/Linux-x86_64/460.56/NVIDIA-Linux-x86_64-460.56.run](https://us.download.nvidia.com/XFree86/Linux-x86_64/460.56/NVIDIA-Linux-x86_64-460.56.run)

* **CUDA** runfiles: `cuda_${toolkit}_${driver}_linux.run` are not compatible.

  However a NVIDIA driver runfile can be extracted intact from a CUDA runfile:
  ```shell
  sh cuda_${toolkit}_${driver}_linux.run --tar mxvf
  > ex: sh cuda_11.2.1_460.32.03_linux.run --tar mxvf

  ls builds/NVIDIA-Linux-${arch}-${driver}.run
  > ex: ls builds/NVIDIA-Linux-x86_460.32.03.run
  ```

### Install build dependencies
> *note:* these are only needed for building not installation

```shell
# Packaging
apt-get install debhelper devscripts dpkg-dev
```


<!--
## Related

- nvidia-modprobe
  * [https://github.com/NVIDIA/debian-packaging-nvidia-modprobe](https://github.com/NVIDIA/debian-packaging-nvidia-modprobe)

- nvidia-settings
  * [https://github.com/NVIDIA/debian-packaging-nvidia-settings](https://github.com/NVIDIA/debian-packaging-nvidia-settings)
-->


## See also

- nvidia-graphics-drivers
  * [https://salsa.debian.org/nvidia-team/nvidia-graphics-drivers](https://salsa.debian.org/nvidia-team/nvidia-graphics-drivers)

### Ubuntu driver

  * [https://github.com/NVIDIA/ubuntu-packaging-nvidia-driver](https://github.com/NVIDIA/ubuntu-packaging-nvidia-driver)

### RHEL driver

  * [https://github.com/NVIDIA/yum-packaging-nvidia-driver](https://github.com/NVIDIA/yum-packaging-nvidia-driver)

### SUSE driver

  * [https://github.com/NVIDIA/zypper-packaging-nvidia-driver](https://github.com/NVIDIA/zypper-packaging-nvidia-driver)


## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md)
