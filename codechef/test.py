import numpy as np 
import random as rs

def generate(size):
	t = 3
	out = []
	out.append(str(3) + "\n")
	while t>0:
		t = t-1
		out.append(str(300) + " " + str(300) + "\n")
		s = "1"*300
		for i in range(300):
			out.append(s + "\n")
	return out

def main():
	filename = "in.txt"
	file = open(filename,"a+")
	file.writelines(generate(1))

if __name__ == "__main__":
	main()
