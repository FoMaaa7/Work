import decimal
print("Введи фамилию (8 букв)")
a=input()
#print(a)
print("Введи отчество (4 буквы)")
b=input()
a1=[]
b1=[]
for character in a:
    number = ord(character)-848
    if(number<8):
        number=number-1
    a1.append(number)
#print(a1)
for character in b:
    number = ord(character)-848
    if(number<8):
        number=number-1
    b1.append(number)
#print(b1)
L0=[]
R0=[]
for i in range(len(a1)):
    if (i<4):
      L0.append(bin(a1[i]))
    else:
      R0.append(bin(a1[i]))
#print(L0)
#print(R0)
X0=[]
for i in range(len(b1)):
      X0.append(bin(b1[i]))
#print(X0)
L01=""
for i in range(len(L0)):
    k= str(L0[i])
    k=k[2:]
    L01=L01+k
#print(L01)
R01=""
for i in range(len(R0)):
    k= str(R0[i])
    k=k[2:]
    R01=R01+k
#print(R01)
X01=""
for i in range(len(X0)):
    k= str(X0[i])
    k=k[2:]
    X01=X01+k
#print(X01)
maska =0b11111111111111111111111111111111;
s=0
carryin = 0
k = 1
a=int(R01,2)
b=int(X01,2)
#print(a+b)
ab=a+b
sm=str(bin(ab))
while(len(sm)>32):
    sm=sm[1:]
print("sum " ,sm)

sum=[[ 4, 14, 5, 7, 6, 4, 13, 1 ],
 [10, 11, 8, 13, 12, 11, 11, 15 ],
 [9, 4, 1, 10, 7, 10, 4, 13],
 [2, 12, 13, 1, 1, 0, 1, 0],
 [13, 6, 10, 0, 5, 7, 3, 5],
 [8, 13, 3, 8, 15, 2, 15, 7],
 [0, 15, 4, 9, 13, 1, 5, 10],
 [14, 10, 2, 15, 8, 13, 9, 4],
 [6, 2, 14, 14, 4, 3, 0, 9],
 [11, 3, 15, 4, 10, 6, 10, 2],
 [1, 8, 12, 6, 9, 8, 14, 3],
 [12, 1, 7, 12, 14, 5, 7, 14],
 [7, 0, 6, 11, 0, 9, 6, 6],
 [15, 7, 0, 2, 3, 12, 8, 11],
 [5, 5, 9, 5, 11, 15, 2, 8],
 [3, 9, 11, 3, 2, 14, 12, 12]]
counter = 7
res=""
#print(sm[0]*8)
for i in range(0,32,4):

    znach = int(sm[i]) * 8 + int(sm[i + 1]) * 4 + int(sm[i + 2]) * 2 + int(sm[i + 3])
    #print(znach)
    binZnach = sum[znach][counter]
    binZnach=bin(binZnach)
    binZnach1=str(binZnach)
    binZnach1=binZnach1[2:]
    if len(binZnach1) < 4:
        for  ii in range(4-len(binZnach1)):
                        res=res+'0'
    for c in binZnach1:
        res=res+c
    counter -= 1
print("perest: ",res)
for i in range(11):
    x=res[0]
    res=res[1:]+x
    #print('.',res)
print("sdwig:", res)
a=int(res,2)
b=int(L01,2)
#print(a,' ',b)
ab=b^a
#print(ab)
s=bin(ab)
#print(s)
s=s[2:]
if len(s)<32:
    s='0'+s
print("Результат: ", s)
#sum=a12&maska
#sum=bin(sum)
