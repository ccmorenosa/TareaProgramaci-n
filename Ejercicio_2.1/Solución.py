import math as mt
import matplotlib.pyplot as plt
import numpy as np

def f(x,g):
    a=mt.cosh(x)
    b=mt.cos(x)
    return a+b-g

def sign(a,b):
    if(a*b<0):
        return True
    elif(a*b>0):
        return False
    else:
        return False
    
def search(f,a,g):
    ya=f(a,g)
    bs=a
    bi=a
    limit=1e3
    k=1
    while(k<=limit):
        bi-=0.01
        bs+=0.01
        if(sign(ya,f(bs,g))):
            return bs
        elif(sign(ya,f(bi,g))):
            return bi
        k+=1
    print('Esta Función no tiene un cambio de signo')
    return None

def bisec(f,a,b,g):
    xi=a
    xf=b
    xm=(xi+xf)/2
    h=1e-10
    while(abs(f(xm,g))>=h):
        if(sign(f(xi,g),f(xm,g))):
            xf=xm
            xm=(xi+xf)/2
        elif(sign(f(xm,g),f(xf,g))):
            xi=xm
            xm=(xi+xf)/2
    return xm

for g in range(1,4):
    x=np.random.rand(1000)*4-2
    y=np.cosh(x)+np.cos(x)-g
    plt.scatter(x,y,s=2)
    plt.grid()
    plt.savefig('Graph_g{}.pdf'.format(g))
    plt.clf()
    a=np.random.rand()*5
    b=search(f,a,g)
    if(b==None):
        continue
    elif(b>a):
        c=bisec(f,a,b,g)
        print("Para g={}, f tiene un cero en: [{},{}], exactamente en x={}, teninedo f(x)={}".format(g,b,a,c,f(c,g)))
        continue
    elif(b<a):
        c=bisec(f,a,b,g)
        print("Para g={}, f tiene un cero en: [{},{}], exactamente en x={}, teninedo f(x)={}".format(g,b,a,c,f(c,g)))
        continue
