n=int(input())
p=[]
for _ in range(n):
    a,s=input().split()
    p.append((int(a),s))
ret=0
l,r=0,0
for a,s in p:
    if s=='L':
        if l==0: l=a
        else:
            ret+=abs(l-a)
            l=a
    if s=='R':
        if r==0: r=a
        else:
            ret+=abs(r-a)
            r=a
print(ret)