import sys
import torch
a=[]
print(sys.getsizeof(a),'байта весит массив',a)
b=[1.2]
print(sys.getsizeof(b),'байта весит массив',b)
x=[1.3, 8.5]
print(sys.getsizeof(x),'байта весит массив',x)
print("1 элемент массива с десятичым числом весит:",sys.getsizeof(x)-sys.getsizeof(b))
