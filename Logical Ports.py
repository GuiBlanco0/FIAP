#Exercise challenge
ocSensor = 1
lumSensor = 0
winSensor = 0
nMode = 0
if (ocSensor and not(lumSensor) and not(winSensor)) or nMode:
    print("Lights ON")
else:
    print("Lights OFF")