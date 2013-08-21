# Copyright (C) 2013 Martin Ertsaas <mertsas@cisco.com>
# Released under the MIT license (see COPYING.MIT for the terms)

require linux-omap.inc

CORTEXA8FIXUP = "no"

SRCREV = "d23689e9f790c136906ea647d555e004851122e9"
SRC_URI = "git://dev.omapzoom.org/pub/scm/integration/kernel-ubuntu.git \
           file://defconfig \
           "

do_compile_kernelmodules_append() {
    oe_runmake ${PARALLEL_MAKE} modules samples CC="${KERNEL_CC}" LD="${KERNEL_LD}"
}

S = "${WORKDIR}/git"
