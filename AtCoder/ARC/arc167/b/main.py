import math
from collections import defaultdict
mod=998244353
def prmfct(n):
  d=defaultdict(int)
  for i in range(2,int(math.sqrt(n))):
    if n%i!=0: continue
    while n%i==0:
      d[i]+=1
      n//=i
  if n!=1: d[n]+=1
  return d

a,b=map(int,input().split())
p=prmfct(a)
cnt=1
for el in p.values(): cnt*=b*el+1
cnt*=b
print((math.floor(cnt/2)+mod)%mod)