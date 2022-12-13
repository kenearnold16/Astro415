import os
import time
t1 = time.time()

os.system("sh final_project.sh")

t2 = time.time()

print("time to run: ", int((t2-t1)/60))
