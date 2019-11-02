import numpy as np
from decimal import *
import math
M = np.ones((8,8))
M = 255*M
m=8
n=8
pi=3.142857
dct = np.ones((m,n))
for i in range(m):
    for j in range(n):
        sum = 0
        for l in range(m):
            for k in range(n):
                theta = (2*k+1)*pi*i/(2*m)
                alpha = (2*l+1)*pi*j/(2*n)
                sum+= M[k][l]*math.cos(theta)*math.cos(alpha)
        if i==0:
            c1 = 1/(m**(1/2))
        else:
            c1 = (2/m)**(1/2)
        if j==0:
            c2 = 1/(n**(1/2))
        else:
            c2 = (2/n)**(1/2)
        dct[i][j]=c1*c2*sum
print(dct)
# dct = ["%.2f"%e for e in dct]
# print(dct)


print(M)
