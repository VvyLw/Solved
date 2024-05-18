#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ranges>
std::vector<int> div(const int n) {
    std::vector<int> d;
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
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for(auto &el: a) {
        std::cin >> el;
    }
    std::unordered_map<int, std::vector<int>> cnt;
    for(const auto i: std::ranges::iota_view(0, n)) {
        for(const auto d: div(a[i])) {
            cnt[d].emplace_back(i);
        }
    }
    while(q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        if(!cnt.contains(k)) {
            std::cout << 0 << '\n';
            continue;
        }
        const auto b = cnt[k];
        std::cout << std::ranges::lower_bound(b, r) - std::ranges::lower_bound(b, l - 1) << '\n';
    }
}