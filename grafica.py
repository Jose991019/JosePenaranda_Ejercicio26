import numpy as np
import matplotlib.pyplot as plt

datos1 = np.loadtxt('euler_0001.dat')

x1 = datos1[:,0]
y1 = datos1[:,1]
z1 = datos1[:,2]

plt.figure(figsize = (10,10))
plt.scatter(x1,y1,s = 0.4,label = 'Explicito')

plt.legend()
plt.savefig('Resultado.png')