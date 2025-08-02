import numpy as np
n = int(input())
a = list(map(int, input().split()))
a.append(-1)
x = np.roots(a)
print("Yes" if any(e > 0 for e in x) else "No")