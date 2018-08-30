import numpy as np 
import random as rs

def generate(size):
	out = []
	n = 100000
	q = 10000
	a = np.random.random_integers(1,1000000000,n)
	out.append(str(n)+ " " + str(q) + "\n")
	a = list(a)
	out.append(" ".join(map(str,a)) + "\n")
	while q>0:
		q = q-1
		l = np.random.randint(1,n)
		r = np.random.randint(l,n)
		x = np.random.randint(1,1000000000)
		out.append(str(l) + " " + str(r) + " " + str(x) + "\n")
	return out

def main():
	filename = "in.txt"
	file = open(filename,"a+")
	file.writelines(generate(1))

if __name__ == "__main__":
	main()
