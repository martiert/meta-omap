DESCRIPTION = "Kernel drivers for the PowerVR SGX chipset in the OMAP4"
LICENSE = "GPLv2 MIT"
PR = "${MACHINE_KERNEL_PR}.0"

inherit module

DEPENDS += "virtual/kernel"

do_compile() {
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
    cd eurasiacon/build/linux2/omap4430_linux
    oe_runmake KERNELDIR=${STAGING_KERNEL_DIR} BUILD=release DISCIMAGE=${D} \
               CC="${KERNEL_CC}" LD="${KERNEL_LD}" kbuild
}

do_install() {
    mkdir -p ${D}/lib/modules/${KERNEL_VERSION}/kernel/drivers/gpu/pvr
    cp ${S}/eurasiacon/binary2_omap4430_linux_release/target/omapdrm_pvr.ko \
       ${D}/lib/modules/${KERNEL_VERSION}/kernel/drivers/gpu/pvr
}

S = "${WORKDIR}/git/sgx"
