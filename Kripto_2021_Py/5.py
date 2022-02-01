import decimal
print("Введи фамилию")
a=input()
#print(a)
print("Введи p")
p=int(input())
print("Введи q")
q=int(input())
n=p*q
eilera=(p-1)*(q-1)
#print(eilera)
print("Введи H0:")
H0=int(input())
def NOD(x,y):

   while (x != y):

       if (x > y):
          x = x - y
       else:
          y = y - x
   return x

def getD(f_n):
    res = -1
    temp = 2
    while (res < 0):
        if (NOD(temp, f_n) == 1 and temp < f_n):
                res = temp
        temp=temp+1
    return res
d=getD(eilera)
#print(d)
def getE(d, f_n):

            e = -1;

            k=1;
            while (e < 0):
                if((f_n * k + 1) % d == 0  ):

                      e = (f_n * k + 1) / d
                else:
                    e=-1
                k=k+1
            #print(k)
            return e
param_e=getE(d,eilera)
#print(param_e)
print("открытый ключ: (", int(param_e), ";", n,")" )
print("закрытый ключ: (", d, ";", n,")" )
output=[]
for character in a:
    number = ord(character)-1038
    if(number<8):
        number=number-1
    output.append(number)
#print(output)
for i in range(len(a)):
    H0=((H0+output[i])*(H0+output[i]))%n
print("Xeш: ", H0)
H01=H0
encr=[]
for i in range(1):
    param_e1=d
    r=1
    while(param_e1):
       if(param_e1 & 1):
           r=r*H0
           r=r%n
       H0=H0*H0
       H0=H0%n
       param_e1>>=1
       #print(r)
    encr.append(r)
print("Подпись: ", encr[0])
for i in range(1):
    param_e1=int(param_e)
    r=1
    while(param_e1):
       if(param_e1 & 1):
           r=r*encr[0]
           r=r%n
       encr[0]=encr[0]*encr[0]
       encr[0]=encr[0]%n
       param_e1>>=1
       #print(r)
    encr.append(r)
print ("Расшифровка подписи: ", encr[1])
if (encr[1]==H01):
    print("Подпись достоверная")
else:
    print("Подпись не достоверная")