/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <hwlcd.hpp>

I2C i2c(I2C_SDA, I2C_SCL);

int main() {
     // Make PA_11 and PA_12 floating that we won't short anything when connecting SDA->PA12 and SCL->PA11
    DigitalIn _(PA_11);
    DigitalIn __(PA_12);
    
    hwlcd lcd(&i2c, i2c_find_first_device(i2c));
    lcd.init(true, false);
    lcd.puts("Hewoo");

    while (true) {}
}
