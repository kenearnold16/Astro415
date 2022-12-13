import numpy as np 
import matplotlib.pyplot as plt
import os 
import pandas as pd

steps = [1,0.5,0.25,0.1]

print('\nLeap Frog Method\n')

for i in range(-1,len(steps)-1):
    i += 1

    os.system('gcc -o homework5_2_leap_frog homework5_2_leap_frog.c -lm')
    os.system('echo ' + str(steps[i]) + ' | ./homework5_2_leap_frog')

    df = pd.read_csv('Leap_Frog.dat', delim_whitespace=True, names=('x','y','v_x','v_y','t'))
    x = df.x
    y = df.y
    v_x = df.v_x
    v_y = df.v_y
    t = df.t

    plt.figure(i)
    plt.plot(x,y,label='steps: ' + str(steps[i]))
    plt.title('Leap frog Method for 2D orbit')
    plt.xlabel('x-position (m)')
    plt.ylabel('y-position (m)')
    plt.grid()
    plt.legend()
    leg = plt.legend(loc='lower left',fontsize=10)

    plt.savefig('./plots/Leap_Frog_' + str(steps[i]) + '.png')
    
    PHI = np.zeros(len(x))
    KE = np.zeros(len(x))
    E = np.zeros(len(x))

    PHI = (-1)/(np.sqrt(1 + (2*(x)**2) + (2*(y)**2)))
    
    KE = ((v_x)**2 + (v_y)**2)*0.5
    
    E = KE + PHI

    plt.figure(i+10)
    plt.plot(t,E,'-b',label='Leap Frog')

print('\nRK4 Method\n')

for i in range(-1,len(steps)-1):
    i += 1

    os.system('gcc -o homework5_2_rk4 ./rk4.c ./NumRec/nrutil.c homework5_2_RK.c -lm')
    os.system('echo ' + str(steps[i]) + ' | ./homework5_2_rk4')

    df = pd.read_csv('RK4.dat', delim_whitespace=True, names=('x','y','v_x','v_y','t'))
    x = df.x
    y = df.y
    v_x = df.v_x
    v_y = df.v_y
    t = df.t

    plt.figure(i+20)
    plt.plot(x,y,label='steps: ' + str(steps[i]))
    plt.title('RK4 Method for 2D Orbit')
    plt.xlabel('x-position (m)')
    plt.ylabel('y-position (m)')
    plt.grid()
    plt.legend()
    leg = plt.legend(loc='lower left',fontsize=10)

    plt.savefig('./plots/RK4_' + str(steps[i]) + '.png')

    PHI = np.zeros(len(x))
    E = np.zeros(len(x))
    KE = np.zeros(len(x))
 
    PHI = (-1)/(np.sqrt(1 + (2*(x)**2) + (2*(y)**2)))

    KE = ((v_x)**2 + (v_y)**2)*0.5
    
    E = KE + PHI

    plt.figure(i+10)
    plt.plot(t,E,'-r',label='RK4')
    plt.title('Energy for step: ' + str(steps[i]))
    plt.xlabel('time (s)')
    plt.ylabel('Energy')
    plt.grid()
    plt.legend()
    leg = plt.legend(loc='upper right',fontsize=10)

    plt.savefig('./plots/Energy_' + str(steps[i]) + '.png')

