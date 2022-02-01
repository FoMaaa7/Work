import decimal
print("Введи фамилию (8 букв)")
a=input()
#print(a)
print("Введи отчество (7 букв)")
b=input()
a1=[]
b1=[]
for character in a:
    number = ord(character)-848
    if(number<8):
        number=number-1
    a1.append(number)
print(a1)
for character in b:
    number = ord(character)-848
    if(number<8):
        number=number-1
    b1.append(number)
print(b1)
L0=[]
for i in range(len(a1)):
      L0.append(bin(a1[i]))
print(L0)
X0=[]
for i in range(len(b1)):
      X0.append(bin(b1[i]))
print(X0)
X01=""
for i in range(len(X0)):
    k= str(X0[i])
    k=k[2:]
    #print(k)
    k=k[:7]
    #print(k)
    X01=X01+k
X01=X01[:48]
print("исключение да 48 битов : ",X01)
L01=""
for i in range(len(L0)):
    k= str(L0[i])
    k=k[2:]
    L01=L01+k
k=L01
replacedText=""
replacedText+=k[57]
replacedText+=k[49]
replacedText+=k[41]
replacedText+=k[33]
replacedText+=k[25]
replacedText+=k[17]
replacedText+=k[9]
replacedText+=k[1]
replacedText+=k[59]
replacedText+=k[51]
replacedText+=k[43]
replacedText+=k[35]
replacedText+=k[27]
replacedText+=k[19]
replacedText+=k[11]
replacedText+=k[3]
replacedText+=k[61]
replacedText+=k[53]
replacedText+=k[45]
replacedText+=k[37]
replacedText+=k[29]
replacedText+=k[21]
replacedText+=k[13]
replacedText+=k[5]
replacedText+=k[63]
replacedText+=k[55]
replacedText+=k[47]
replacedText+=k[39]
replacedText+=k[31]
replacedText+=k[23]
replacedText+=k[15]
replacedText+=k[7]
replacedText+=k[56]
replacedText+=k[48]
replacedText+=k[40]
replacedText+=k[32]
replacedText+=k[24]
replacedText+=k[16]
replacedText+=k[8]
replacedText+=k[0]
replacedText+=k[58]
replacedText+=k[50]
replacedText+=k[42]
replacedText+=k[34]
replacedText+=k[26]
replacedText+=k[18]
replacedText+=k[10]
replacedText+=k[2]
replacedText+=k[60]
replacedText+=k[52]
replacedText+=k[44]
replacedText+=k[36]
replacedText+=k[28]
replacedText+=k[20]
replacedText+=k[12]
replacedText+=k[4]
replacedText+=k[62]
replacedText+=k[54]
replacedText+=k[46]
replacedText+=k[38]
replacedText+=k[30]
replacedText+=k[22]
replacedText+=k[14]
replacedText+=k[6]
print("1 perest: ", replacedText)
L0=""
R0=""
for i in range(len(replacedText)):
    if (i<32):
      L0+=replacedText[i]
    else:
      R0+=replacedText[i]
#print(L0)
#print(R0)
result =""
k=R0
for i in range(0,32,4):
  if(i - 1 < 0):
    result+=k[31]
  else:
    result+=k[i-1]
  result+=k[i]
  result+=k[i + 1]
  result+=k[i + 2]
  result+=k[i + 3]
  if   (i + 4 > 31):
      result+=k[0]
  else:
      result += k[i + 4]
print("удлиннение R0: ",result)
r0=int(result,2)
x0=int(X01,2)
#print(r0, ' ', x0)
rx=r0^x0
rx1=bin(rx)
rx11=str(rx1)
rx11=rx11[2:]
while(len(rx11)<48):
    rx11='0'+rx11
print("sum: ", rx11)
r=[]
for i in range(len(rx11)):
    r.append(int(rx11[i]))
s1 = [[14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7],
[0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8],
[4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0],
[15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13]]

s2 =[[15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10],
[3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5],
[0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15],
[13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9]]
s3 =[[10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8],
[13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1],
[13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7],
[1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12]]
s4 = [[7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15],
[13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9],
[10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4],
[3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14]]
s5 =[[2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9],
[14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6],
[4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14],
[11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3]]
s6 =[[12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11],
[10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8],
[9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6],
[4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13]]

s7 =[[4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1],
[13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6],
[1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,3],
[6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12]]
s8 =[[13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7],
[1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2],
[7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8],
[2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11]]
result=""
#print(r)
fromS1 = s1[r[0] * 2 + r[5]][r[1] * 8 + r[2] * 4 + r[3] * 2 + r[4]]
fromS11=bin(fromS1)
fromS12=str(fromS11)
fromS12= fromS12[2:]
while  len(fromS12)<4:
    fromS12='0'+fromS12
result=result+fromS12
#print(r[6] * 2 + r[11])
#print(r[7] * 8 + r[8] * 4 + r[9] * 2 + r[10])
fromS2 = s2[r[6] * 2 + r[11]][r[7] * 8 + r[8] * 4 + r[9] * 2 + r[10]]
#print(fromS2)
fromS21=bin(fromS2)
fromS22=str(fromS21)
fromS22= fromS22[2:]
while  len(fromS22)<4:
    fromS22='0'+fromS22
result=result+fromS22

fromS3 = s3[r[12] * 2 + r[17]][r[13] * 8 + r[14] * 4 + r[15] * 2 + r[16]]
fromS31=bin(fromS3)
fromS32=str(fromS31)
fromS32= fromS32[2:]
while  len(fromS32)<4:
    fromS32='0'+fromS32
result=result+fromS32
fromS4 = s4[r[18] * 2 + r[23]][r[19] * 8 + r[20] * 4 + r[21] * 2 + r[22]]
fromS41=bin(fromS4)
fromS42=str(fromS41)
fromS42= fromS42[2:]
while  len(fromS42)<4:
    fromS42='0'+fromS42
result=result+fromS42
fromS5 = s5[r[24] * 2 + r[29]][r[25] * 8 + r[26] * 4 + r[27] * 2 + r[28]]
fromS51=bin(fromS5)
fromS52=str(fromS51)
fromS52= fromS52[2:]
while  len(fromS52)<4:
    fromS52='0'+fromS52
result=result+fromS52

fromS6 = s6[r[30] * 2 + r[35]][r[31] * 8 + r[32] * 4 + r[33] * 2 + r[34]]
fromS61=bin(fromS6)
fromS62=str(fromS61)
fromS62= fromS62[2:]
while  len(fromS62)<4:
    fromS62='0'+fromS62
result=result+fromS62

fromS7 = s7[r[36] * 2 + r[41]][r[37] * 8 + r[38] * 4 + r[39] * 2 + r[40]]
fromS71=bin(fromS7)
fromS72=str(fromS71)
fromS72= fromS72[2:]
while  len(fromS72)<4:
    fromS72='0'+fromS72
result=result+fromS72

fromS8 = s8[r[42] * 2 + r[47]][r[43] * 8 + r[44] * 4 + r[45] * 2 + r[46]]
fromS81=bin(fromS8)
fromS82=str(fromS81)
fromS82= fromS82[2:]
while  len(fromS82)<4:
    fromS82='0'+fromS82
result=result+fromS82

print("S-Box: ", result)
r1=result
print(r1[0])
result=""
result+=r1[15]
result+=r1[6]
result+=r1[19]
result+=r1[20]
result+=r1[28]
result+=r1[11]
result+=r1[27]
result+=r1[16]
result+=r1[0]
result+=r1[14]
result+=r1[22]
result+=r1[25]
result+=r1[4]
result+=r1[17]
result+=r1[30]
result+=r1[9]
result+=r1[1]
result+=r1[7]
result+=r1[23]
result+=r1[13]
result+=r1[31]
result+=r1[26]
result+=r1[2]
result+=r1[8]
result+=r1[18]
result+=r1[12]
result+=r1[29]
result+=r1[5]
result+=r1[21]
result+=r1[10]
result+=r1[3]
result+=r1[24]
print("предпоследняя перестановка: " ,result)
#print(result)
#print(L0)
r2=result
r2=int(result,2)
r3=int(L0,2)
r2=r2^r3
print(r2)
rx1=bin(r2)
rx11=str(rx1)
r2=rx11[2:]
while(len(r2)<32):
    r2='0'+r2
print(L0)
print("summa: ", r2)
r2=r2+L0
result=""
result+=r2[39]
result+=r2[7]
result+=r2[47]
result+=r2[15]
result+=r2[55]
result+=r2[23]
result+=r2[63]
result+=r2[31]
result+=r2[38]
result+=r2[6]
result+=r2[46]
result+=r2[14]
result+=r2[54]
result+=r2[22]
result+=r2[62]
result+=r2[30]
result+=r2[37]
result+=r2[5]
result+=r2[45]
result+=r2[13]
result+=r2[53]
result+=r2[21]
result+=r2[61]
result+=r2[29]
result+=r2[36]
result+=r2[4]
result+=r2[44]
result+=r2[12]
result+=r2[52]
result+=r2[20]
result+=r2[60]
result+=r2[28]
result+=r2[35]
result+=r2[3]
result+=r2[43]
result+=r2[11]
result+=r2[51]
result+=r2[19]
result+=r2[59]
result+=r2[27]
result+=r2[34]
result+=r2[2]
result+=r2[42]
result+=r2[10]
result+=r2[50]
result+=r2[18]
result+=r2[58]
result+=r2[26]
result+=r2[31]
result+=r2[1]
result+=r2[41]
result+=r2[9]
result+=r2[49]
result+=r2[17]
result+=r2[57]
result+=r2[25]
result+=r2[32]
result+=r2[0]
result+=r2[40]
result+=r2[8]
result+=r2[48]
result+=r2[16]
result+=r2[56]
result+=r2[24]
print("Результат: ", result)