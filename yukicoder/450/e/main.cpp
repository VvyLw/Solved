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
#include <atcoder/modint>
namespace man {
typedef atcoder::modint998244353 mint;
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int64_t m;
    int n;
    std::cin >> m >> n;
    std::valarray<int64_t> x(n + 2);
    for(const auto i: iota(1) | take(n)) {
        std::cin >> x[i];
    }
    x[0] = 0;
    x[n + 1] = m;
    dump(x);
    man::mint ret = 0;
    for(const auto i: iota(0, n + 1)) {
        const man::mint z = x[i + 1] - x[i] - (i < n);
        ret += z * (z + 1) * (2 * z + 1) / 6;
    }
    std::cout << ret.val() << '\n';
}