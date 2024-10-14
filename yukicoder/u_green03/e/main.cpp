#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <ranges>
#include <valarray>
#include <vector>
#include <cmath>
#include <unordered_set>
namespace man {
constexpr inline long double dist(const std::pair<int, int> &p, const std::pair<int, int> &q) noexcept {
    return std::hypotl(p.first - q.first, p.second - q.second);
}
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int n, k;
    std::cin >> n >> k;
    std::valarray<int> h(n);
    for(auto &e: h) {
        std::cin >> e;
    }
    std::vector<std::pair<int, int>> pos(n);
    for(auto &[x, y]: pos) {
        std::cin >> x >> y;
    }
    std::unordered_set<int> del;
    for(const auto i: iota(0, n)) {
        for(const auto j: iota(i + 1, n)) {
            if(man::dist(pos[i], pos[j]) <= k) {
                if(h[i] == h[j]) {
                    continue;
                }
                del.emplace(h[i] < h[j] ? i : j);
            }
        }
    }
    std::cout << n - del.size() << '\n';
}