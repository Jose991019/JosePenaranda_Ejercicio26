import numpy as np
import matplotlib.pyplot as plt

datos1 = np.loadtxt('euler_0001.dat')
datos2 = np.loadtxt('RK4_0001.dat')
datos3 = np.loadtxt('leap_frog_0001.dat')


x1 = datos1[:,0]
y1 = datos1[:,1]
z1 = datos1[:,2]

x2 = datos2[:,0]
y2 = datos2[:,1]
z2 = datos2[:,2]

x3 = datos3[:,0]
y3 = datos3[:,1]
z3 = datos3[:,2]

plt.figure(figsize = (10,10))

plt.subplot(3,3,1)
plt.plot(x1,y1)
plt.xlabel('x')
plt.ylabel('y')
plt.ylim((-1.5,1.5))


plt.subplot(3,3,2)
plt.plot(x2,y2)
plt.xlabel('x')
plt.ylabel('y')
plt.ylim((-1.5,1.5))


plt.subplot(3,3,3)
plt.plot(x3,y3)
plt.xlabel('y')
plt.ylabel('y')
plt.ylim((-1.5,1.5))


plt.subplot(3,3,4)
plt.plot(x1,z1)
plt.xlabel('x')
plt.ylabel('dy/dx')
plt.ylim((-1.5,1.5))



plt.subplot(3,3,5)
plt.plot(x2,z2)
plt.xlabel('x')
plt.ylabel('dy/dx')
plt.ylim((-1.5,1.5))


plt.subplot(3,3,6)
plt.plot(x3,z3)
plt.xlabel('x')
plt.ylabel('dy/dx')
plt.ylim((-1.5,1.5))


plt.subplot(3,3,7)
plt.plot(y1,z1)
plt.xlabel('y')
plt.ylabel('dy/dx')
plt.xlim((-2,2))
plt.ylim((-2,2))



plt.subplot(3,3,8)
plt.plot(y2,z2)
plt.xlabel('y')
plt.ylabel('dy/dx')
plt.xlim((-2,2))
plt.ylim((-2,2))


plt.subplot(3,3,9)
plt.plot(y3,z3)
plt.xlabel('y')
plt.ylabel('dy/dx')
plt.xlim((-2,2))
plt.ylim((-2,2))



plt.savefig('Resultado.png')