#!/usr/bin/env python
# Sept 2009

def nqueens(n):
    a = [0 for i in range(n)]
    i = 0
    while (1):
        while collision(a,i) and a[i] < n:
            a[i] += 1
        if a[i] == n:
            a[i] = 0
            i -= 1
            if i < 0:
                return [0 for i in range(0,n)]
            a[i] += 1
        else:
            i += 1
            if i == n:
                return a

def collision(a,i):
    for j in range(i):
        if (a[i] == a[j]) or (a[i] - a[j] - i + j == 0) or (a[i] - a[j] - j + i == 0):
            return 1
    return 0

n = 25
a = nqueens(n)
for i in range(n):
    print a[i]*"o" + "X" + (n-a[i]-1)*"o"
