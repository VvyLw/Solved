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
#include <atcoder/math>
#include <atcoder/modint>
namespace man {
typedef atcoder::modint998244353 mint;
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int n;
    std::cin >> n;
    man::mint ret = 0;
    for(const auto i: iota(1) | take(n)) {
        ret += atcoder::floor_sum(n + 1, i, 1, 0);
    }
    std::cout << ret.val() << '\n';
}