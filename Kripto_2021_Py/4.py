import decimal
print("Введи фамилию")
a=input()
#print(a)
print("Введи p")
p=int(input())
print("Введи q")
q=int(input())
print("Введи H0:")
H0=int(input())
n=p*q
eilera=(p-1)*(q-1)
#print(eilera)
output=[]
for character in a:
    number = ord(character)-1038
    if(number<8):
        number=number-1
    output.append(number)
print(output)
for i in range(len(a)):
    H0=((H0+output[i])*(H0+output[i]))%n
print(H0)
