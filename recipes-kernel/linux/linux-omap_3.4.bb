# Copyright (C) 2013 Martin Ertsaas <mertsas@cisco.com>
# Released under the MIT license (see COPYING.MIT for the terms)

require linux-omap.inc

CORTEXA8FIXUP = "no"

SRCREV = "dedf4afe9aa5d03fdd1e420959f39d3224e9bdc3"
SRC_URI = "git://dev.omapzoom.org/pub/scm/integration/kernel-ubuntu.git;branch=ti-ubuntu-3.4-1489 \
           file://defconfig \
           "

do_compile_kernelmodules_append() {
    oe_runmake ${PARALLEL_MAKE} modules samples CC="${KERNEL_CC}" LD="${KERNEL_LD}"
}

S = "${WORKDIR}/git"
