n = int(input())
s = [input() for _ in range(n)]
cnt = 0
for i in range(n):
    r = [0] * 2
    for j in range(n):
        if s[i][j] == 'A': r[0] += 1
        elif s[i][j] == '.': r[1] += 1
    if r[0] == n - 1 and r[1] == 1: cnt += 1
for i in range(n):
    c = [0] * 2
    for j in range(n):
        if s[j][i] == 'A': c[0] += 1
        elif s[j][i] == '.': c[1] += 1
    if c[0] == n - 1 and c[1] == 1: cnt += 1
x = [0] * 2
for i in range(n):
    if s[i][i] == 'A': x[0] += 1
    elif s[i][i] == '.': x[1] += 1
if x[0] == n - 1 and x[1] == 1: cnt += 1
x = [0] * 2
for i in range(n):
    if s[i][n - 1 - i] == 'A': x[0] += 1
    elif s[i][n - 1 - i] == '.': x[1] += 1
if x[0] == n - 1 and x[1] == 1: cnt += 1
print(cnt)