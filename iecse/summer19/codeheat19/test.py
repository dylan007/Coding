x = int(input())
for i in range(1,x):
    for j in range(i,x):
        if((i*j)%x == 1):
            print(i,j,i*j,(i*j)%x)
