def nth_palindrome(n):
    if n <= 0:
        return -1  # 非負の整数でない場合はエラーを返します

    if n == 1:
        return 0  # 1番目の回文数は0

    # 1を引いて他のアルゴリズムと合わせる
    n -= 1
    
    def count_palindromes_with_length(length):
        if length == 1:
            return 9  # 1, 2, ..., 9
        half_length = (length + 1) // 2
        return 9 * (10 ** (half_length - 1))  # 例えば、長さ3なら900個 (100から999)

    length = 1
    total_count = 0
    
    while True:
        count = count_palindromes_with_length(length)
        if total_count + count >= n:
            break
        total_count += count
        length += 1

    remaining = n - total_count
    half_length = (length + 1) // 2
    start = 10 ** (half_length - 1)
    num = start + remaining - 1

    s = str(num)
    if length % 2 == 0:
        return int(s + s[::-1])
    else:
        return int(s + s[-2::-1])

# 1番目の回文数を求める
print(nth_palindrome(int(input())))
