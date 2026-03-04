A = 0
B = 0
C = 0
D = 0

print("A B C D | X")
for A in range(2):
  for B in range(2):
    for C in range(2):
     for D in range(2):
         X = 0
         if not(A) and B and C and not(A or D):
            X = 1
 
         print(A,B,C,D,'|', X)