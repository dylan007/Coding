import random as rs
import numpy as np 


arr = [[0]*10]*10
for i in range(10):
	for j in range(10):
		arr[i][j] = rs.randint(0,1)

print("1")
print("10 10")
for i in range(10):
	print("".join(list(map(str,arr[i]))))
