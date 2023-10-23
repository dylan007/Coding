import itertools


def calculate_cost(arr):
    n = len(arr)
    cost = 0
    for i in range(n-1):
        m = arr[i]
        p = i
        for j in range(i+1, n):
            if(arr[j] < m):
                m = arr[j]
                p = j
        cost += (p - i + 1)
        arr[i:p+1] = arr[i:p+1][::-1]
    return cost


T = int(input())
for t in range(1, T+1):
    n, cost = map(int, input().split())
    perms = list(itertools.permutations(list(range(1, n+1))))
    out = []
    for perm in perms:
        arr = list(perm[::])
        c = calculate_cost(arr)
        if(c == cost):
            out = perm[::]
            break
    if(len(out) == 0):
        print("Case #{}: {}".format(t, "IMPOSSIBLE"))
    else:
        print("Case #{}: {}".format(t, ' '.join(map(str, out))))
