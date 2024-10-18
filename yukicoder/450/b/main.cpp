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
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int n;
    std::cin >> n;
    std::valarray<int> a(n);
    for(auto &e: a) {
        std::cin >> e;
    }
    int ans = 0;
    for(const auto i: iota(0, n)) {
        for(const auto j: iota(0, n)) {
            ans += std::abs(i - j) * std::abs(a[i] - a[j]);
        }
    }
    std::cout << ans << '\n';
}