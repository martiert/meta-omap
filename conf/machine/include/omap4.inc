SOC_FAMILY = "omap4"

require conf/machine/include/soc-family.inc
require conf/machine/include/tune-cortexa9.inc

PREFERRED_PROVIDER_virtual/kernel = "linux-omap"
PREFERRED_VERSION_virtual/kernel = "3.4%"
PREFERRED_PROVIDER_virtual/bootloader = "u-boot"
PREFERRED_VERSION_u-boot = "v2013.01%"

PREFERRED_PROVIDER_virtual/egl = "pvr-omap4"
PREFERRED_PROVIDER_virtual/libgles1 = "pvr-omap4"
PREFERRED_PROVIDER_virtual/libgles2 = "pvr-omap4"

PREFERRED_PROVIDER_virtual/xserver = "xserver-xorg"
XSERVER = "xserver-xorg \
           xserver-xorg-module-exa \
           xf86-input-evdev \
           pvr-omap4"

# Increase this everytime you change something in the kernel
MACHINE_KERNEL_PR = "r1"

KERNEL_IMAGETYPE = "uImage"

UBOOT_MACHINE := "omap4_panda_config"

UBOOT_ENTRYPOINT := "0x80008000"
UBOOT_LOADADDRESS := "0x80008000"

EXTRA_IMAGEDEPENDS += "u-boot"
