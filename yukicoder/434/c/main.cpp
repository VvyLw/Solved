#include <iostream>
#include <vector>
#include "C++/math/Modint.hpp"
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<mint> dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        if(i + k <= n) {
            dp[i + k] += dp[i];
        }
        dp[i + 1] += dp[i];
    }
    std::cout << dp[n] << '\n';
}