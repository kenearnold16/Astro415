import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

filename = "output.txt"
table = pd.read_csv(filename, delim_whitespace=True)

table_col = ['add_5','minus_5','times_1','div_1','sqrt_1','pow_05']
calculation_type =['addition','subtraction','multiplication','division','sqrt','power']
for i in range(-1, len(table) - 2):
    i +=1
    y = table[table_col[i]]
    x = table['integer']
    
    plt.figure(1)
    plt.plot(x,y,label = calculation_type[i])
plt.xlabel('log(n) iterations')
plt.ylabel('log(Time) (s)')
plt.yscale('log')
plt.xscale('log')
plt.legend()
plt.grid()
plt.title('Time vs n Number of iterations Optimized (Log scale)')

plt.savefig('Time_vs_n_optimized.png')
