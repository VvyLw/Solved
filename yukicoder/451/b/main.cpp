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
#include <atcoder/dsu>
namespace man {
constexpr inline bool scope(const int l, const int x, const int r) noexcept { return l <= x && x < r; }
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> g(h);
    for(auto &t: g) {
        std::cin >> t;
        assert(std::ssize(t) == w);
    }
    const auto encrypt = [&w](const int i, const int j) -> int { return i * w + j; };
    atcoder::dsu uf(h * w);
    for(const auto i: iota(0, h)) {
        for(const auto j: iota(0, w)) {
            if(g[i][j] == '.') {
                continue;
            }
            if(man::scope(0, i + 1, h) && g[i][j] == g[i + 1][j]) {
                uf.merge(encrypt(i, j), encrypt(i + 1, j));
            }
            if(man::scope(0, j + 1, w) && g[i][j] == g[i][j + 1]) {
                uf.merge(encrypt(i, j), encrypt(i, j + 1));
            }
        }
    }
    for(const auto i: iota(0, h)) {
        for(const auto j: iota(0, w)) {
            std::cout << (uf.size(encrypt(i, j)) >= 4 ? '.' : g[i][j]);
        }
        std::cout << '\n';
    }
}