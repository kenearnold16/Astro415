import os
import time
t1 = time.time()

os.system("sh bonus.sh")

t2 = time.time()

print("time to run: ", int((t2-t1)/60))
