s,t=input().split()
n,m=len(s),len(t)
for i in range(1,n):
    for j in range(1,i+1):
        if m>(n-j)//i+1: continue
        u=""
        for k in range(j-1,n,i):
            u+=s[k]
            if len(u)==m: break
        if t==u: exit(print("Yes"))
print("No")