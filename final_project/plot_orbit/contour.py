import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import os
import sys
from tqdm import tqdm
import imageio

method = 'lf'
N = int(sys.argv[1])
speed = eval(sys.argv[2])

df = pd.read_csv(method + '.txt',delim_whitespace=True,names=['particle','mass','time','x','y','z','vx','vy','vz'])
x = df['x']
y = df['y']
z = df['z']
m = df.mass


limit = eval(sys.argv[3])
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
    plt.clim(0,3)
    plt.xlabel('parsecs')
    plt.ylabel('parsecs')
    plt.title('time = ' + str(int(time[k-1]*1e6)) + 'yrs')
    filename = '2dcountour' + str(k) + '.png'
    filenames.append(filename)
    plt.savefig(filename)
    if(k == 25):
        plt.savefig('time_15_plot.png', dpi=300, bbox_inches='tight')
    

with imageio.get_writer('finalproj.gif', mode='I') as writer:
     for filename in filenames:
         image = imageio.imread(filename)
         writer.append_data(image)


for filename in set(filenames):
    os.remove(filename)

