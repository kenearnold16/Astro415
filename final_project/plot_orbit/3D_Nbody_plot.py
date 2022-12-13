import numpy as np 
import matplotlib.pyplot as plt 
import pandas as pd 
import imageio
import os
from tqdm import tqdm
import sys

method = 'lf'
N = int(sys.argv[1])
speed = eval(sys.argv[2])
limit = eval(sys.argv[3])

df = pd.read_csv(method + '.txt',delim_whitespace=True,names=['particle','mass','time','x','y','z','vx','vy','vz'])
x = df['x']
y = df['y']
z = df['z']
m = df.mass

x_max = limit
y_max = limit
z_max = limit
x_min= -limit
y_min = -limit
z_min = -limit

t = df.time

p = df.particle

n = int(len(x)/N)

time = np.linspace(min(t),max(t),n)

x1 = np.zeros(n)
y1 = np.zeros(n)
z1 = np.zeros(n)

p_index = np.zeros((n, N))
filenames = []

n = int((len(x1)/speed))
l = -1
for k in tqdm(range(-1,n-1)):
    k+=1
    plt.figure(k)
    ax = plt.axes(projection='3d')
    
    for i in (range(0, N)):
        i+=1
        l+=1
        index = np.where(p == i)
        #p_index[:,i-1] = index[0]
        
        x1 = x[index[0]]
        y1 = y[index[0]]
        z1 = z[index[0]]
        
        if m[l] > 9:
            color = 'blue'

        else:
            color = 'red'
            
        ax.plot3D(x1[index[0][speed*k]], y1[index[0][speed*k]], z1[index[0][speed*k]], '.', markersize = 1, color = color)
        #plt.plot(x1[index[0][speed*k]], y1[index[0][speed*k]],'o', color = color)
        #plt.xlim([-60, 60])
        #plt.ylim([-60,60])
        
     #plt.plot(x1[0:speed*k],y1[0:speed*k],'--r')
     #plt.plot(x2[0:speed*k],y2[0:speed*k],'--b')
        
    ax.set_xlim(x_min, x_max); ax.set_ylim(y_min, y_max); ax.set_zlim(z_min, z_max);
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_zlabel('z')
          
    filename = str(i) + '_' + str(k) + '.png'
    filenames.append(filename)
    plt.savefig(filename)
    
with imageio.get_writer(method+ '_orbit.gif', mode='I') as writer:
     for filename in filenames:
         image = imageio.imread(filename)
         writer.append_data(image)

for filename in set(filenames):
    os.remove(filename)
