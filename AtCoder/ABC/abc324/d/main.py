import math
_=input()
s=input()
cnt=[0]*10
for x in s: cnt[int(x)]+=1
lim=int(''.join(sorted(s,reverse=True)))
ans=0
for i in range(0,int(math.sqrt(lim))+1):
    t=str(i*i)
    tmp=[0]*10
    for x in t: tmp[int(x)]+=1
    if len(s)>len(t): tmp[0]+=len(s)-len(t)
    if cnt==tmp: ans+=1
print(ans)