#include <iostream>
#include <vector>
#include <algorithm>
inline std::vector<int64_t> div(const int64_t n) noexcept {
    std::vector<int64_t> d;
    for(int64_t i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            d.emplace_back(i);
            if(i * i != n) {
                d.emplace_back(n / i);
            }
        }
    }
    std::ranges::sort(d);
    return d;
}
inline int64_t solve() noexcept {
    int64_t a, b;
    std::cin >> a >> b;
    if(a == b) {
        return 0;
    }
    const auto d = div(b - a);
    const auto it = std::ranges::lower_bound(d, a);
    return it == d.cend() ? -1 : *it - a;
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    std::cin >> t;
    while(t--) {
        std::cout << solve() << '\n';
    }
}