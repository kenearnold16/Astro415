import numpy as np 
import matplotlib.pyplot as plt
import os 

steps = [1,0.3,0.1,0.03, 0.01]

print('\nEuler Method\n')

x_exact = np.sin(15)

for i in range(-1,len(steps)-1):
    i += 1

    os.system('gcc -o homework5_1_Euler homework5_1_Euler.c -lm')
    os.system('echo ' + str(steps[i]) + ' | ./homework5_1_Euler')
    
    x,t = np.genfromtxt('Euler_Method.dat', unpack = 'True')
    plt.figure(1)
    plt.plot(t,x,label='steps: ' + str(steps[i]))
    plt.title('Euler Method for $\dfrac{d^{2}x}{dt^{2}}$ = -x')
    plt.xlabel('time (s)')
    plt.ylabel('position (m)')
    plt.grid()
    plt.legend()
    leg = plt.legend(loc='lower left',fontsize=10)
    
    Y_residual = np.log10(abs((x[len(x)-1]) - x_exact))

    plt.figure(2)
    plt.plot(np.log10(steps[i]), Y_residual, 'or')
    plt.title('Euler Method residuals at t=15s')
    plt.xlabel('$\log_{10}(N)$')
    plt.ylabel('$\log_{10}(residuals)$')
    plt.grid()

plt.figure(1)
plt.savefig('./plots/Euler_Method.png')

plt.figure(2)
plt.savefig('./plots/log_Euler.png')

print('plot saved as Euler_Method.png\n')

print('\nLeap Frog Method\n')

for i in range(-1,len(steps)-1):
    i += 1

    os.system('gcc -o homework5_1_leap_frog homework5_1_leap_frog.c -lm')
    os.system('echo ' + str(steps[i]) + ' | ./homework5_1_leap_frog')

    x,t = np.genfromtxt('Leap_Frog.dat', unpack = 'True')
    plt.figure(3)
    plt.plot(t,x,label='steps: ' + str(steps[i]))
    plt.title('Leap frog Method for $\dfrac{d^{2}x}{dt^{2}}$ = -x')
    plt.xlabel('time (s)')
    plt.ylabel('position (m)')
    plt.grid()
    plt.legend()
    leg = plt.legend(loc='lower left',fontsize=10)

    Y_residual = np.log10(abs((x[len(x)-1]) - x_exact))

    plt.figure(4)
    plt.plot(np.log10(steps[i]), Y_residual, 'or')
    plt.title('Leap Frog residuals at t=15s')
    plt.xlabel('$\log_{10}(N)$')
    plt.ylabel('$\log_{10}(residuals)$')
    plt.grid()

plt.figure(3)
plt.savefig('./plots/Leap_Frog.png')

plt.figure(4)
plt.savefig('./plots/log_leap_frog.png')

print('plot saved as Leap_Frog.png\n')

print('\nRK4 Method\n')

for i in range(-1,len(steps)-1):
    i += 1

    os.system('gcc -o homework5_1_rk4 ./rk4.c ./NumRec/nrutil.c homework5_1_RK.c -lm')
    os.system('echo ' + str(steps[i]) + ' | ./homework5_1_rk4')

    x,t = np.genfromtxt('RK4.dat', unpack = 'True')
    plt.figure(5)
    plt.plot(t,x,label='steps: ' + str(steps[i]))
    plt.title('RK4 Method for $\dfrac{d^{2}x}{dt^{2}}$ = -x')
    plt.xlabel('time (s)')
    plt.ylabel('position (m)')
    plt.grid()
    plt.legend()
    leg = plt.legend(loc='lower left',fontsize=10)

    Y_residual = np.log10(abs((x[len(x)-1]) - x_exact))

    plt.figure(6)
    plt.plot(np.log10(steps[i]), Y_residual, 'or')
    plt.title('RK4 residuals at t=15s')
    plt.xlabel('$\log_{10}(N)$')
    plt.ylabel('$\log_{10}(residuals)$')
    plt.grid()

plt.figure(5)
plt.savefig('./plots/RK4.png')

plt.figure(6)
plt.savefig('./plots/RK4_frog.png')

print('plot saved as RK4.png\n')


