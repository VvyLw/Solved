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
#include <cmath>
#include <algorithm>
namespace man {
inline int solve() noexcept {
    int n, m;
    std::cin >> n >> m;
    int need = std::ceil(n / 4.0L);
    m -= (8 * need - n);
    need += std::max<int>(0, std::ceil(m / 8.0L));
    dump(m, need);
    return need;
}
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int t;
    std::cin >> t;
    for([[maybe_unused]] const auto _: iota(0, t)) {
        std::cout << man::solve() << '\n';
    }
}