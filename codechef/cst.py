import numpy

t = input()
while t>0:
    n,m,k = map(int,input().split())
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

det = numpy.linalg.det(matrix)
print(det)
