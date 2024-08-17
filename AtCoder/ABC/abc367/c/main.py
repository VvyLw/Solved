from itertools import product
_,k=map(int,input().split())
r=list(map(int,input().split()))
pat=[range(1,e+1) for e in r]
comb=list(product(*pat))
for e in list(product(*pat)):
    if sum(e)%k==0: print(*e)