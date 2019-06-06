#include <Cosa/TWI.hh>
#include <Cosa/UART.hh>
#include <Cosa/Trace.hh>
#include <ctype.h>

// values configurable
#define MIN_ADDRESS 0x00
#define MAX_ADDRESS 0x7F
#define SCAN_DELAY 5000

#define TEST_DATA 0x00

void setup() {
  uart.begin(9600);
  trace.begin(&uart, PSTR("I2C Scanner: Started"));
}

void loop() {
  uint8_t num_devices = 0;

  for (uint8_t address = MIN_ADDRESS; address < MAX_ADDRESS; ++address) {
    TWI::Driver driver{address};
    twi.acquire(&driver);

    auto status = twi.write(TEST_DATA, sizeof(TEST_DATA));
    if (status == sizeof(TEST_DATA)) {
      // found the device
      trace << PSTR("I2C device found at address ") << hex << address << endl;
      ++num_devices;
    }

    twi.release();
  }

  if (num_devices <= 0) {
    trace << PSTR("No I2C devices found") << endl;
  } else {
    trace << PSTR("Done!") << endl;
  }

  delay(SCAN_DELAY);
}

