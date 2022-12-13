import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

Mass_file = 'Mass.dat'
P_file = 'P_inv.dat'

Mass_frame = pd.read_csv(Mass_file, delim_whitespace=True, header=0)
N = Mass_frame.N
M = Mass_frame.M
sigma = Mass_frame['+-sigma']

P = np.genfromtxt(P_file, unpack = 'True')

plt.figure(1)
plt.hist(P, bins = 200)
plt.xlabel('Bin value of P_inv')
plt.ylabel('Frequency')
plt.title('Histogram of P_inv')
plt.grid()

plt.savefig('P_inv_Hist.png')

plt.figure(2)
plt.errorbar(np.log10(N),M,sigma, marker='o',ecolor='r', linestyle='')
plt.xlabel('log(N)')
plt.ylabel('Mass')
plt.title('Mass calculated by Monte Carlo Method')
plt.grid()

plt.savefig('Mass.png')

