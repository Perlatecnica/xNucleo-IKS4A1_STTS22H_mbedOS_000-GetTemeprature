# xNucleo-IKS4A1_STTS22H_mbedOS_000-GetTemeperature

This code snippet is a simple example demonstrating the usage of the STTS22H temperature sensor with the ARM mbed platform. Here's a breakdown of what it does:

1. It includes necessary libraries like "mbed.h" and "STTS22H.h" for hardware abstraction and STTS22H sensor functionalities.
2. Initializes the STTS22H sensor object `sensor` using the specified I2C pins `I2C_SDA` and `I2C_SCL`.
3. Sets up a serial connection `pc` for communication with the host computer.
4. Defines a digital output pin `led` to control an LED (though it's not utilized in this code).
5. Sets the baud rate for serial communication and sends an introductory message to the host computer.
6. Initializes the sensor and enables it for temperature reading.
7. Reads the sensor's ID and prints it out.
8. Enters a continuous loop where it:
   - Reads the temperature from the sensor.
   - Prints the temperature over the serial connection.
   - Delays execution for 1 second before repeating the process.

Overall, this code reads temperature data from the STTS22H sensor at regular intervals and outputs it to a serial terminal for monitoring.
