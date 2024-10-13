brew install arduino-cli

arduino-cli version

arduino-cli core install arduino:avr

arduino-cli board list

???? arduino-cli board attach --fqbn arduino:avr:uno /ruta/a/tu/proyecto

arduino-cli compile --fqbn arduino:avr:mega /Users/fermin/Desktop/micros/rfid/rfid.ino

arduino-cli upload --fqbn arduino:avr:mega -p /dev/tty.usbmodem141201 /Users/fermin/Desktop/micros/rfid/rfid.ino

arduino-cli monitor -p /dev/tty.usbmodem141201 -c baudrate=9600