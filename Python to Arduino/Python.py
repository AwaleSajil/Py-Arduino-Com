import serial
import time

arduinoData = serial.Serial('com4', 9600)

def led_on():
	arduinoData.write(b'1')	#write(b'1')

def led_off():
	arduinoData.write(b'0')

while True:
	led_off()
	time.sleep(1) #delay 1 sec
	led_on()
	time.sleep(1)
