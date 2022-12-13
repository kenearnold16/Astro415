import matplotlib.pyplot as plt
import pandas as pd

execution_times = pd.read_csv("execution_time.dat", delim_whitespace=True, names=('N','(A)','(B)'))

N = execution_times['N']
time_A = execution_times['(A)']
time_B = execution_times['(B)']

plt.figure(1)
plt.plot(N, time_A,'b', label='fast index row')
plt.plot(N, time_B,'r', label='fast index column')

plt.xlabel('N')
plt.ylabel('Execution times')
plt.title('Execution times for appending matrix elements')
plt.legend()

plt.savefig('execution_times.png')

