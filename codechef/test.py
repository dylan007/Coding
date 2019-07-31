def isPrime(x):
    curr=2
    while curr*curr <= x:
        if (x%curr) == 0:
            return False
        curr+=1
    return True

x = int(input())
for i in range(2,100):
    if(isPrime(i)):
        print(i,x%i,(x**2)%i)

