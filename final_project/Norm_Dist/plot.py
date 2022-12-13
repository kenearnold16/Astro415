# Make sure to run this code in Python environment with matplotlib!!!

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from scipy.special import erfinv
import os

# Make sure current working directory is set to this folder (i.e. path/to/Biniam_HW3_ASTR415)!!!
path = os.getcwd();
# print(path);

# Code was used to test "norm_example.c"; if changing mean and variance in norm_example.c, change it here as well (lines 24-25)

columns = ['Normal']
data = pd.read_csv("./norm_dist.txt", sep = " ", names=columns);
N = len(data);
print("Number of Deviates: "+str(N));

print(data);

Norm = np.asarray(data['Normal']);

mean = 5;
var = 1;
bin = 300;
bin_size = (np.max(Norm) - np.min(Norm))/bin;

# code below used to plot histogram:

fig = plt.figure(figsize=[15,8]);
weight = (1/N)*np.ones(np.size(Norm));
histo = plt.hist(Norm, bins=bin, weights=weight, edgecolor='black');

x = np.linspace(np.min(Norm), np.max(Norm), N);
# print(x);
py = np.zeros(N);
for i in range(len(py)):
    py[i] = bin_size*np.exp(-((x[i] - mean)**2)/(2*var))/np.sqrt(2*var*np.pi);
# print(py);

line = plt.plot(x, py);
plt.title("Histogram ");
plt.xlabel("Value");
plt.ylabel("Probability");
# plt.xlim(-3, 3);
plt.tight_layout();
# plt.savefig('Histogram.png', dpi = 600);
plt.show()

# # code below used to plot erfinv testing
# columns = ['x', 'erfinv(x)']
# data = pd.read_csv("./erfinv.txt", sep = " ", names=columns);
# N = len(data);

# x = np.asarray(data['x']);
# erfinv_test = np.asarray(data['erfinv(x)']);

# plt.figure(figsize=(15,8));
# plt.xlim(-1.1, 1.1);
# plt.plot(x, erfinv_test, label="Maclaurin");
# plt.plot(x, erfinv(x), label="True");
# plt.title("Approximation of $erf^{-1}(x)$ Using Maclaurin Series");
# plt.ylabel("$erf^{-1}(x)$");
# plt.xlabel("$x$");
# plt.legend();
# plt.savefig("erfinv", dpi = 600);