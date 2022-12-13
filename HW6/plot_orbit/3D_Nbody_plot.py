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

df = pd.read_csv(method + '.txt',delim_whitespace=True,names=['particle','mass','time','x','y','z','vx','vy','vz'])
x = df['x']
y = df['y']
z = df['z']
m = df.mass

x_mean = np.mean(x)
y_mean = np.mean(y)
z_mean = np.mean(z)
x_std = np.std(x)
y_std = np.std(y)
z_std = np.std(z)
d_from_mx = abs(x - x_mean)
d_from_my = abs(y - y_mean)
d_from_mz = abs(z - z_mean)
max_deviations = 1
increase_dev = 1000

x_not_outlier = d_from_mx < max_deviations * x_std
y_not_outlier = d_from_my < max_deviations * y_std
z_not_outlier = d_from_mz < max_deviations * z_std

x_no_outliers = x[x_not_outlier]
y_no_outliers = y[y_not_outlier]
z_no_outliers = z[z_not_outlier]

x_max = np.mean(x_no_outliers) + increase_dev
y_max = np.mean(y_no_outliers) + increase_dev
z_max = np.mean(z_no_outliers) + increase_dev
x_min= -np.mean(x_no_outliers) - increase_dev
y_min = -np.mean(y_no_outliers) - increase_dev
z_min = -np.mean(z_no_outliers) - increase_dev

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
            
        ax.plot3D(x1[index[0][speed*k]], y1[index[0][speed*k]], z1[index[0][speed*k]], 'o', color = color)
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
