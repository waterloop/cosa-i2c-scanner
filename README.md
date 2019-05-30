# Cosa I2C Scanner

This is a scanner for scanning connected I2C devices. If a device is found, it is reported to the serial monitor.
This shows the 7-bit addresses of the found devices as hexadecimal values. That value can be used for the
`TWI driver` which uses the 7-bit address. Some datasheets use the 8-bit address.

Minimum address and Maximum address can be changed by modifying the defines.

To build this application:
```bash
wio build
```

To run this application:
```bash
wio run
```

To monitor the serial output:
```bash
wio monitor <port>
```
