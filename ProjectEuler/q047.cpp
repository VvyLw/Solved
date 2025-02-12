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
#include <cassert>
#include <unordered_set>
#include <C++/math/primefactortable.hpp>
namespace man {
constexpr inline int pow(int a, int b) noexcept {
    int res = 1;
    while(b > 0) {
        if(b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}
}
constexpr int n = 1000000;
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    Heileden::p_fact p(n);
    for(const auto i: iota(1, n)) {    
        std::unordered_set<int> s;
        for(const auto j: iota(0, 4)) {
            const auto q = p.get(i + j);
            for(const auto &[k, v]: q) {
                s.emplace(man::pow(k, v));
            }
        }
        if(std::ssize(s) == 16) {
            std::cout << i << '\n';
            return 0;
        }
    }
}