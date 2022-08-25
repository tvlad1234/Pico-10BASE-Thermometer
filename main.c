#include "pico/stdlib.h"

#include "10baset.h"
#include "bmp085.h"

int main()
{

    /// Place your IP addresses
    eth_set_ip(192, 168, 131, 176);   /// here
    eth_set_dest(192, 168, 131, 140); /// and here

    // Initialize Ethernet
    eth_core_start();

    // Initialize sensor
    BMP085_setI2C(i2c_default, 0, 1, 0x77); // SDA on GPIO0, SCL on GPIO1
    bool bmpOK = BMP085_init(BMP085_STANDARD);

    int counter = 0;
    float temp, pres;

    while (1)
    {
        if (bmpOK)
        {
            temp = BMP085_readTemperature();
            pres = BMP085_readPressure() / 100.0;
            udp_printf("%.1f °C  %.1f hPa  %d\n", temp, pres, counter);
        }
        else
        {
            udp_printf("Sensor error!\n");
        }

        counter++;
        sleep_ms(2500);
    }
}