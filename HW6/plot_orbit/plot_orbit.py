import numpy as np 
import matplotlib.pyplot as plt 
import pandas as pd 
import imageio
import os
from tqdm import tqdm
import sys

method = (sys.argv[1])
ecc = (sys.argv[2])
speed = eval(sys.argv[3])

df = pd.read_csv(ecc + method + '.txt',delim_whitespace=True,names=['particle','time','x','y','z','vx','vy','vz'])
x = df['x']
y = df['y']
vx = df.vx
vy = df.vy
t = df.time
p = df.particle

p1_index = np.where(p == 1)
p2_index = np.where(p == 2)

n = int(len(x)/2)
time = np.linspace(min(t),max(t),n)

x1 = np.zeros(n)
y1 = np.zeros(n)
vx1 = np.zeros(n)
vy1 = np.zeros(n)
vx2 = np.zeros(n)
vy2 = np.zeros(n)
x2 = np.zeros(n)
y2 = np.zeros(n)
filenames = []

for i in range(-1, len(x1)-1):
    i += 1
    x1[i] = x[p1_index[0][i]]
    y1[i] = y[p1_index[0][i]]
    vx1[i] = vx[p1_index[0][i]]
    vy1[i] = vy[p1_index[0][i]]
    
    x2[i] = x[p2_index[0][i]]
    y2[i] = y[p2_index[0][i]]
    vx2[i] = vx[p2_index[0][i]]
    vy2[i] = vy[p2_index[0][i]]

n = int(len(x2)/speed)

for i in tqdm(range(-1,n-1)):
    i+=1
    plt.figure(i)
    plt.plot(x1[speed*i],y1[speed*i],'or')
    plt.plot(x1[0:speed*i],y1[0:speed*i],'--r')
    plt.plot(x2[speed*i],y2[speed*i],'ob')
    plt.plot(x2[0:speed*i],y2[0:speed*i],'--b')
    plt.grid()
    
    plt.xlim([-1,1])
    plt.ylim([-1,1])
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title(method + ' method for eccentricity ' + ecc)
    
    filename = str(i) + '_' + '.png'
    filenames.append(filename)
    plt.savefig(filename)
    
with imageio.get_writer(ecc + method+ '_orbit.gif', mode='I') as writer:
     for filename in filenames:
         image = imageio.imread(filename)
         writer.append_data(image)

for filename in set(filenames):
    os.remove(filename)

E = (0.5*(np.sqrt((vx1**2) + (vy1**2))**2)) + (0.5*(np.sqrt((vx2**2) + (vy2**2)))) - (1/(np.sqrt(((x2-x1)**2) + ((y2-y1)**2))))
plt.figure(i + 1)
plt.plot(time,E,'r')
plt.xlabel('Time')
plt.ylabel('Energy')
plt.title('Energy vs Time for ' + method + ' and ecc ' + ecc)
plt.grid()

plt.savefig('Energy_' + method + ecc + '.png')

rx = (x2-x1)
ry = (y2-y1)

r = np.sqrt(rx**2 + ry**2)

vx = (vx2 - vx1)
vy = (vy2 - vy1)

v_r = (vx*rx + vy*ry)/r

plt.figure(i+2)
plt.plot(r,v_r,'g')
plt.xlabel('r - separation')
plt.ylabel('v - radial velocity')
plt.title('Phase for ' + method + ' and ecc ' + ecc)
plt.grid()

plt.savefig('phase_plot_' + method + ecc + '.png')

