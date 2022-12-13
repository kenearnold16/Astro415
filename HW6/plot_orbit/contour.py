import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import os
import sys
from tqdm import tqdm
import imageio

method = 'lf'
N = 1000
speed = 20

df = pd.read_csv(method + '.txt',delim_whitespace=True,names=['particle','mass','time','x','y','z','vx','vy','vz'])
x = df['x']
y = df['y']
z = df['z']
m = df.mass


limit = 75
x_max = limit
y_max = limit
z_max = limit
x_min= -limit
y_min = -limit
z_min = -limit

t = df.time

n = int((len(x)/N)/speed)

time = np.linspace(min(t),max(t),n)


filenames = []

for k in tqdm(range(-1, n)):
    k+=1
    plt.figure(k)
    im = plt.hist2d(x[k*N*speed:k*N*speed+1000], y[k*N*speed:k*N*speed+1000], bins=150, range=([-limit, limit], [-limit, limit]), cmap='copper')
    plt.xlim([-limit, limit])
    plt.ylim([-limit, limit])
    cb = plt.colorbar()
    cb.set_label('Number of Bodies')
    plt.clim(0,5)
    filename = '2dcountour' + str(k) + '.png'
    filenames.append(filename)
    plt.savefig(filename)

with imageio.get_writer('finalproj.gif', mode='I') as writer:
     for filename in filenames:
         image = imageio.imread(filename)
         writer.append_data(image)

os.system('rm *.png')


