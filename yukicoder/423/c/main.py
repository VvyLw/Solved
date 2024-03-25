n, p, k = map(int, input().split())
dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
dp[0][0] = p
for i in range(n):
    t, b = map(int, input().split())
    for j in range(n):
        if t == 1:
            x = dp[i][j] + b
            if x > 10 ** 18: exit(print(-1))
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], x)
        else:
            x = dp[i][j] * 2
            if x > 10 ** 18: exit(print(-1))
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], x)
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j])
print(dp[n][k])