# solved by GPT-4o(test)
def card_game_winner(N, A, B):
    from functools import lru_cache

    @lru_cache(None)
    def can_win(state):
        for i in range(N):
            if not (state & (1 << i)):
                continue
            for j in range(i + 1, N):
                if not (state & (1 << j)):
                    continue
                if A[i] == A[j] or B[i] == B[j]:
                    next_state = state & ~(1 << i) & ~(1 << j)
                    if not can_win(next_state):
                        return True
        return False

    initial_state = (1 << N) - 1
    return "Takahashi" if can_win(initial_state) else "Aoki"

# 入力の読み込み
N = int(input())
A = []
B = []
for _ in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

# 結果の出力
print(card_game_winner(N, A, B))