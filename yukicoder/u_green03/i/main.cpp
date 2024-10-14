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
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
namespace man {
typedef __int128_t i128;
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int q;
    int64_t y;
    std::cin >> q >> y;
    std::vector<std::string> s(q);
    for(auto &t: s) {
        std::cin >> t;
    }
    const auto f = [&s](const man::i128 x) -> man::i128 {
        std::stack<man::i128> sk;
        for(const auto &t: s) {
            if(t == "+" || t == "min" || t == "max") {
                const man::i128 y = sk.top();
                sk.pop();
                const man::i128 x = sk.top();
                sk.pop();
                if(t == "+") {
                    sk.emplace(x + y);
                } else if(t == "min") {
                    sk.emplace(std::min(x, y));
                } else {
                    sk.emplace(std::max(x, y));
                }
            } else {
                sk.emplace(t == "X" ? x : std::stol(t));
            }
        }
        return sk.top();
    };
    int64_t ok = (1L << 61) - 1, ng = -1;
    while(std::abs(ok - ng) > 1) {
        const man::i128 x = ((man::i128) ok + ng) / 2;
        (f(x) >= y ? ok : ng) = x;
    }
    std::cout << (f(ok) == y ? ok : -1) << '\n';
}