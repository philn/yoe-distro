DISTRO_FEATURES_remove = " x11 wayland"

# Use bcm userland graphics driver
DISABLE_VC4GRAPHICS = "1"

# Use rdk backend for eglfs
PREFERRED_PROVIDER_virtual/wpebackend = "wpebackend-rdk"

PACKAGECONFIG_pn-wpebackend-rdk_rpi = "rpi"
