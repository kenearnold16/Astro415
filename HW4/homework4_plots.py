import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

Mass_file = 'Mass.dat'
P_file = 'P_inv.dat'

Mass_frame = pd.read_csv(Mass_file, delim_whitespace=True, header=0)
N = Mass_frame.N
M = Mass_frame.M
sigma = Mass_frame['+-sigma']

P_inv = np.genfromtxt(P_file, unpack = 'True')

weights = (1/len(P_inv))*np.ones(len(P_inv))
u = np.linspace(0,5,1000)

bins = 200

plt.figure(1)
x, y, _ = plt.hist(P_inv, bins = bins, weights = weights, label = 'histogram data')

bin_size = y.max()/200
P_inv_function = bin_size*(u*np.exp(-(u**2)/2))

plt.plot(u,P_inv_function,'r', label='theory curve')
plt.xlabel('Bin value of P_inv')
plt.ylabel('Weighted Frequency')
plt.title('Histogram of P_inv')
plt.grid()
plt.legend()
plt.savefig('P_inv.png')

plt.figure(2)
plt.errorbar(np.log10(N),M,sigma, marker='o',ecolor='r', linestyle='')
plt.xlabel('log(N)')
plt.ylabel('Mass')
plt.title('Mass calculated by Monte Carlo Method')
plt.grid()
plt.savefig('Mass.png')



