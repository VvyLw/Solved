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
#include <algorithm>
#include <numeric>
#include "C++/math/pollard_rho.hpp"
namespace man {
constexpr uint LIM = 2e5;
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int64_t x;
    std::cin >> x;
    if(x == 1) {
        std::cout << "2\n1 2\nb g\n";
        std::exit(0);
    }
    auto pf = rho(x);
    while(std::ssize(pf) > 1) {
        std::ranges::sort(pf, std::greater<>());
        const auto l = pf.back();
        pf.pop_back();
        const auto r = pf.back();
        if(l * r <= l + r + 1) {
            pf.pop_back();
            pf.emplace_back(l * r);
        } else {
            pf.emplace_back(l);
            break;
        }
    }
    dump(pf);
    const int n = std::ssize(pf);
    const auto ret = std::accumulate(pf.cbegin(), pf.cend(), 0L) + n;
    if(ret > man::LIM) {
        std::cout << "-1\n";
        std::exit(0);
    }
    std::cout << ret << '\n';
    for(const auto i: iota(1) | take(n - 1)) {
        std::cout << i << ' ' << i + 1 << '\n';
    }
    int k = n;
    for(const auto i: iota(0, n)) {
        for([[maybe_unused]] const auto _: iota(0U, pf[i])) {
            std::cout << i + 1 << ' ' << ++k << '\n';
        }
    }
    for([[maybe_unused]] const auto _: iota(0, n)) {
        std::cout << "b ";
    }
    for(const auto i: iota(0, ret - n)) {
        std::cout << 'g' << " \n"[i + 1 == ret - n];
    }
}