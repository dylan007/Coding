import random as rs
import numpy as np 


def gen():
	n = rs.randint(1,100000)
	k = rs.randint(1,n-1)
	q = 3 * (10 ** 5)
	s = ""
	for i in range(n):
		if rs.uniform(0.0,1.0)>=0.5 :
			s += "1 "
		else:
			s += "0 "
	query = ""
	for i in range(q):
		if rs.uniform(0.0,1.0)>=0.5 :
			query += "?"
		else:
			query += "!"
	out = []
	out.append(str(n) + " " + str(q) + " " + str(k) + "\n")
	out.append(s + "\n")
	out.append(query)
	return out

def main():
	filename = "in.txt"
	file = open(filename,"a+")
	file.writelines(gen())

if __name__ == "__main__":
	main()
