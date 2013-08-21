DESCRIPTION = "Binary blob for PowerVR sgx in OMAP4"
LICENSE = "Proprietary"

DEPENDS += "pvr-omap4-dkms drm"
PROVIDES += "virtual/egl virtual/libgles1 virtual/libgles2"

do_install() {
    cp -r usr "${D}/"
    rm -fR "${D}/usr/share/doc"

    cd "${D}/usr/share"
    mv sgx-lib pvr-omap4-data
    ln -s pvr-omap4-data sgx-lib

    install -d "${D}${libdir}/.debug"
    install -d "${D}${bindir}/.debug"
    mv ${D}${libdir}/debug${libdir}/* "${D}${libdir}/.debug"
    mv ${D}${libdir}/debug${bindir}/* "${D}${bindir}/.debug"

    rm -fr "${D}${libdir}/debug"
    rm -fr "${D}${libdir}/xorg"
}

S = "${WORKDIR}/git"

FILES_${PN} += "\
    /usr/share \
    /usr/lib/gbm \
    "

FILES_${PN}-dbg += "\
    ${libdir}/.debug \
    ${bindir}/.debug \
    "

PACKAGEBUILDPKGD := "${@'${PACKAGEBUILDPKGD}'.replace('split_and_strip_files', '')}"

QAPATHTEST[useless-rpaths] = ""
QAPATHTEST[dev-so] = ""
