n=int(input())
m=[(1<<i)-1 for i in range(n+2)]
# print(m)
prod=1
for i in range(2,n+1): prod*=m[i]
print("Yes" if prod%m[-1]==0 else "No")