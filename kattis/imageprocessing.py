h,w,n,m = map(int,raw_input().split())
img = []
for i in range(h):
	x = map(int,raw_input().split())
	img.append(x)
ker = []
for i in range(n):
	x = map(int,raw_input().split())
	ker.insert(0,x[::-1])
ans = []
for i in range(h-n+1):
	x = []
	for j in range(w-m+1):
		y = 0
		for k in range(i,i+n):
			for p in range(j,j+m):
				y += ker[k-i][p-j]*img[k][p]
		print y,
	print ""
