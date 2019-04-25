import numpy as np
import matplotlib.pyplot as plt

datos1 = np.loadtxt('euler_0001.dat')
datos2 = np.loadtxt('RK4_0001.dat')

x1 = datos1[:,0]
y1 = datos1[:,1]
z1 = datos1[:,2]

x2 = datos2[:,0]
y2 = datos2[:,1]
z2 = datos2[:,2]

plt.figure(figsize = (10,10))

plt.subplot(3,1,1)
plt.scatter(x2,y2,s = 0.4)
plt.xlabel('x')
plt.ylabel('y')


plt.subplot(3,1,2)
plt.scatter(x2,z2,s = 0.4)
plt.xlabel('x')
plt.ylabel('dy/dx')

plt.subplot(3,1,3)
plt.scatter(y2,z2,s = 0.4)
plt.xlabel('y')
plt.ylabel('dy/dx')

plt.savefig('Resultado.png')