import serial

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.flush()

    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            file = open("/var/www/html/data.txt", "w")
            file.write(line)
            file.close()

            print(line)