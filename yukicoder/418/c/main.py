import sys
sys.set_int_max_str_digits(4*10**6)
def main():
    n,m=map(int, input().split())
    print((n*(n+1)//2)%m)
for _ in range(int(input())): main()