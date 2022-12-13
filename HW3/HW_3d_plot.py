import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

filename = 'ps2.dat'
frame = pd.read_csv(filename, delim_whitespace=True, names=('x', 'y', 'z', 'v_x','v_y','v_z'))

x = frame.x
y = frame.y
z = frame.z 

v_x = frame.v_x
v_y = frame.v_y
v_z = frame.v_z

v = np.sqrt((v_x**2) + (v_y**2) + (v_z**2))
v_min = min(v)
v_max = max(v)

fig = plt.figure()
ax = plt.axes(projection='3d')

p = ax.scatter(x, y, z,'.', c=v)
cbar = fig.colorbar(p, ax = ax, location = 'left')
cbar.set_label('tangent velocity (m/s)')

ax.set_xlabel('x (m)')
ax.set_zlabel('y (m)')
ax.set_ylabel('z (m)')

plt.yticks([-1000, 0, 1000]) 
plt.xticks([-1000, 0, 1000]) 

ax.set_title('Instantaneous spin of body')

plt.savefig('3D_body_plot.png')
