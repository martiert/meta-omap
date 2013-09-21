require recipes-bsp/u-boot/u-boot.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=1707d6db1d42237583f50183a5651ecb \
                    file://README;beginline=1;endline=22;md5=78b195c11cb6ef63e6985140db7d7bab"

PV = "v2013.01.01"
SRC_URI = "git://git.denx.de/u-boot.git;branch=master;tag=${PV}"

S = "${WORKDIR}/git"
