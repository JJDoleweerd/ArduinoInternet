arduino-cli compile -b arduino:avr:uno
arduino-cli upload --fqbn arduino:avr:uno -p /dev/cu.usbserial-1410
cat /dev/cu.usbserial-1410