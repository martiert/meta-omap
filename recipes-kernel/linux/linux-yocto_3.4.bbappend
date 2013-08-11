COMPATIBLE_MACHINE_pandaboard = "pandaboard"

SRCREV_machine_pandaboard ?= "7eb5fbf903d9db90c3cf371b65e1f2a68d5676d7"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-3.4:"

SRC_URI += "file://defconfig \
            file://pandaboard-standard.scc "
