def solve(H, W, A, B):
    ans = float('inf')

    # 行の入れ替え
    for i in range(H):
        diff = [B[i][j] - A[i][j] for j in range(W)]
        count = sum([1 for d in diff if d != 0])
        ans = min(ans, count)

    # 列の入れ替え
    for j in range(W):
        diff = [B[i][j] - A[i][j] for i in range(H)]
        count = sum([1 for d in diff if d != 0])
        ans = min(ans, count)

    if ans == float('inf'):
        return -1  # 一致不可能な場合
    else:
        return ans

# 入力を受け取る
H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
B = [list(map(int, input().split())) for _ in range(H)]

# 問題を解く
result = solve(H, W, A, B)

# 結果を出力
print(result)
