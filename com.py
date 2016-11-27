import serial
from urllib import request as req
from urllib.parse import urlparse

ser = serial.Serial('COM4', 9600, timeout=0)
previous = "";

lien = req.build_opener()

while(True):
    text = ser.readline().rstrip()
    if(text != previous and text != b''):
        previous = text
        print(text)
        if(text == b'1') :
            print("ON A UN NOUVEAU MESSAGE")
            lien.open("http://213.32.88.151/push.php")
