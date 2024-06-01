MOD = 998244353

def solve(N, M):
    total_sum = 0
    # 最大60ビットまで
    for i in range(60):
        bit_mask = 1 << i
        
        # N + 1 までの数における i ビット目が 1 になる数を数える
        total_bit_count = ((N + 1) // (bit_mask << 1)) * bit_mask
        remainder = (N + 1) % (bit_mask << 1)
        total_bit_count += max(0, remainder - bit_mask)

        # Mのiビット目が1なら、そのビット位置のポピュレーションカウントを計算
        if M & bit_mask:
            total_sum += total_bit_count
            total_sum %= MOD

    return total_sum

# 入力の例（実際の問題では適切な方法で入力を受け取る）
N,M=map(int,input().split())

print(solve(N, M))  # 結果の表示
