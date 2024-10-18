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
#include <cstdint>
#include <bit>
#include <algorithm>
namespace man {
inline int64_t solve() noexcept {
    uint64_t n;
    std::cin >> n;
    int64_t ret = 0;
    const int m = std::bit_width(n);
    for(const auto i: std::views::iota(0, m)) {
        const int64_t x = (1L << i);
        ret += ((n + 1) / (x << 1)) * x;
        ret += std::max<int64_t>(0, (n + 1) % (x << 1) - x);
    }
    return ret;
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