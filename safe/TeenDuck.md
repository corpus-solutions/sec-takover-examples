# TeenDuck

**Cyber-weaponizing Teensy ++2.0**

### Installation

Follow steps on https://pjrc.com to upgrade your Arduino IDE with Teensyduino extensions.

### Masquerade

In case you're targeting Mac OS X, you'll want to adjust Vendor and Product ID of the USB mode to simulate real Mac keyboard that does not seem suspicious to the system (you would be presented with a dialog for setting keyboard type, which is easier to avoid than mitigate).

Find installation of your Teensy core in Arduino libs and edit `usb_private.h` and `usb_desc.h` like this:

```
// Mac OS-X and Linux automatically load the correct drivers.  On
// Windows, even though the driver is supplied by Microsoft, an
// INF file is needed to load the driver.  These numbers need to
// match the INF file.
#define VENDOR_ID               0x05AC
#define PRODUCT_ID              0x021E
```

1. Find VENDOR_ID `0x16C0` and replace with `0x05AC` in `**/*.h` files.
1. Find PRODUCT_ID `0x0487` and replace with `0x021E` in `**/*.h` files.

