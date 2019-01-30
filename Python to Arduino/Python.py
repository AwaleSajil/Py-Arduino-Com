import serial
import time

arduinoData = serial.Serial('com4', 9600)

def led_on():
	arduinoData.write(b'1')	#write(b'1')

def led_off():
	arduinoData.write(b'0')

for i in range(10):
	led_off()
	time.sleep(0.1) #delay 1 sec
	led_on()
	time.sleep(0.1)


arduinoData.close()
