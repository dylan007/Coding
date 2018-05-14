def bin_search(arr,start,end,item):
    if(start<0 or end>=len(arr)):
        return False
    if(start>end):
        return False
    mid = (start+end)/2
    if(arr[mid] == item):
        return True
    if(arr[mid]>item):
        return bin_search(arr,start,mid-1,item)
    else:
        return bin_search(arr,mid+1,end,item)


def generateRandomNumbers(size,flag):
    r = 1000000007
    m1 = 2017
    m2 = 2027
    l = 0
    sl = 1
    m = 0
    ans = [] 
    for i in range(size):
        n = ((l * m1) + (sl * m2) + m) % r + 1
        sl = l
        l = n
        ans.append(n)
    return ans

size,Q = map(int,raw_input().split())
flag = [0]*100010
ANS = generateRandomNumbers(size,flag)
ANS.sort()
while Q>0:
    Q -= 1
    x = input()
    if bin_search(ANS,0,size-1,x):
        print "YES"
    else:
        print "NO"
