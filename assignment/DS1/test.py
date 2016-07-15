import random,string
from random import randint

k = random.randint(1,10)
arr = ['J','M','R']

print ''.join(random.choice(arr) for _ in range(k))
