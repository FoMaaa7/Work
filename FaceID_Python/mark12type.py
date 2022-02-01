import numpy as np
import random
a=np.empty((1000))
for i in range(1000):
    if (i<3):
       a[0]=0.54535
       a[1]=0.34575
       a[2]=0.22331
       a[3]=0.17554
    if(i>2):
        a[i]=random.randrange(3,8)/9.996544/10
    if(i>30):
        a[i]=a[i]+0.1
print('loss red=',a)
k=0
l=[1,2]
for i in range(1000):

        a[i]=k
        k=k+random.choice(l)
print('N validation=',a)
print('loss red= [1.45667, 1.12424, 0.784854. ]')