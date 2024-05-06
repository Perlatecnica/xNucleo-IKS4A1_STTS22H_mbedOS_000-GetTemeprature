/*
MIT License

Copyright (c) [2024] 
Organization: Perlatecnica APS ETS
Author: Mauro D'Angelo
Example Example to use the STTS22H temperature measurement sensor

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "mbed.h"
#include "STTS22H.h"


STTS22H sensor(I2C_SDA, I2C_SCL); 

Serial pc(USBTX, USBRX);
DigitalOut led(LED1);



// main() runs in its own thread in the OS
int main()
{

    pc.baud(115200);
    pc.printf("Example to use the STTS22G temperature sensor\r\n");

    sensor.begin();
    sensor.Enable();

    uint8_t Id;
    sensor.ReadID(&Id);

    printf("%d",Id);

    while (true) {
        float temperature = 0.0;
        // Read temperature
        sensor.GetTemperature(&temperature);
        // Output data
        pc.printf("Temperature: %f\r\n", temperature);
        ThisThread::sleep_for(1000);
    }
}
