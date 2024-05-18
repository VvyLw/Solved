#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
constexpr int64_t INF = (1LL << 61) - 1;
template <class T, class U> constexpr inline bool chmin(T& a, const U& b) noexcept { if(a>b){ a=b; return 1; } return 0; }
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n), b(q);
    for(auto &el: a) {
        std::cin >> el;
    }
    for(auto &el: b) {
        std::cin >> el;
    }
    std::vector<int64_t> dp(n, INF);
    dp[0] = 0;
    for(const auto e: b) {
        for(const auto i: std::views::iota(0, n - 1)) {
            chmin(dp[i + 1], dp[i] + 1);
        }
        for(const auto i: std::views::iota(1, n) | std::views::reverse) {
            chmin(dp[i - 1], dp[i] + 1);
        }
        for(const auto i: std::views::iota(0, n)) {
            if(a[i] != e) {
                dp[i] = INF;
            }
        }
    }
    std::cout << *std::ranges::min_element(dp) << '\n';
}