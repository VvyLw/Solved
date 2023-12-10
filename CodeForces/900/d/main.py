def main():
    n,k=map(int,input().split())
    s=input()
    l=list(map(int, input().split()))
    r=list(map(int, input().split()))
    q=int(input())
    x=list(map(int, input().split()))
    interval_index=[-1]*(n+1)
    for i in range(k):
        for j in range(l[i],r[i]+1): interval_index[j]=i
    for el in x[::-1]:
        interval_idx=interval_index[el]
        li, ri = l[interval_idx], r[interval_idx]
        a = min(el, ri + li - el)
        b = max(el, ri + li - el)
        s = s[:a - 1] + s[a - 1:b][::-1] + s[b:]
    print(s)
for _ in range(int(input())): main()