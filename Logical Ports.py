#A security system opens the door only when the card
#and the fingerprint matches, or if the emergency key was used (C = 1)
#Logical expression - A*B+C = X
card = 0
fgp = 0
key = 1

if card * fgp + key:
    print("OPEN DOOR")
else:
    print("CLOSED DOOR")
