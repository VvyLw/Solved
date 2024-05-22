#wrong answer
from fractions import Fraction
pat=set()
n=43200
cnt=0
for i in range(0,n+1):
    # 時針
    h=Fraction(i%n,120)
    # 分針
    m=Fraction(i%3600,10)
    # 秒針
    s=Fraction(6*i%60,1)
    # hm=abs(h-m)
    # hs=abs(h-s)
    # ms=abs(m-s)
    x=tuple(sorted([h,m,s]))
    if x in pat:
        #print(x)
        cnt+=1
    pat.add(x)
print(cnt)