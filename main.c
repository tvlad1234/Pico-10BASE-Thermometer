#include "pico/stdlib.h"

#include "10baset.h"
#include "bmp085.h"

int main()
{
    // Initialize LED pin
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    /// Set the IP addresses. Replace with ones coresponding to your configuration.
    eth_set_ip(192, 168, 131, 179);   /// here
    dest_ip_t dst_ip = {192,168,131,146}; /// and here

    // Set the UDP port
    uint16_t dst_port = 1234;

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
            udp_printf(dst_ip, dst_port, "%.1f °C  %.1f hPa  %d\n", temp, pres, counter);
        }
        else
        {
             udp_printf(dst_ip, dst_port, "Sensor init error!\n");
        }

        gpio_put(PICO_DEFAULT_LED_PIN, counter % 2); // blink the LED
        counter++;

        sleep_ms(2500);
    }
}
