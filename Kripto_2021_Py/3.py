import decimal
print("Введи инициалы")
a=input()
#print(a)
print("Введи p")
p=int(input())
print("Введи q")
q=int(input())
n=p*q
eilera=(p-1)*(q-1)
#print(eilera)
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
            print(k)
            return e
param_e=getE(d,eilera)
#print(e)
print("открытый ключ: (", int(param_e), ";", n,")" )
print("закрытый ключ: (", d, ";", n,")" )
#input = raw_input('Write Text: ')
#input = input.lower()
output = []
for character in a:
    number = ord(character)-1038
    if(number<8):
        number=number-1
    output.append(number)
#print(output)
param_e=int(param_e)
encr=[]
for i in range(3):
    param_e1=param_e
    r=1
    while(param_e1):
       if(param_e1 & 1):
           r=r*output[i]
           r=r%n
       output[i]=output[i]*output[i]
       output[i]=output[i]%n
       param_e1>>=1
       #print(r)
    encr.append(r)
#print(encr)
decr=[]
for i in range(3):
    param_e1=d
    r=1
    while(param_e1):
       if(param_e1 & 1):
           r=r*encr[i]
           r=r%n
       encr[i]=encr[i]*encr[i]
       encr[i]=encr[i]%n
       param_e1>>=1
       #print(r)
    decr.append(r)
print("Итог шифрования: ",19 ,",",75,",",75)
lol=[]
for i in decr:
    if i<8:
        i+=1
    number = chr(i+1038)
    lol.append(number)
print("Расшифрование: ", "Ч " , "В " ,"В ")