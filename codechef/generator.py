import numpy as np
import random as rs

def generate(size,limit):
	output = []
	output.append(str(10) + "\n")
	for t in range(10):
		k = np.random.randint(1,limit)
		output.append(str(size) + " " + str(k) + "\n")
		arr = map(int,list(np.random.random_integers(1,limit,size)))
		output.append(" ".join(map(str,arr)) + "\n")
	return output

def main():
	filename = "./in"
	file = open(filename,"a+")
	file.writelines(generate(5000,10000))

if __name__ == "__main__":
	main()