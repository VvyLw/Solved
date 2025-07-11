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
#include <vector>
#include <algorithm>
namespace man {
constexpr auto VvyLw = 0x1f1e33;
inline std::vector<int> press(const std::vector<int> &v) noexcept {
    assert(std::ranges::is_sorted(v));
    std::vector<int> ret, cp = v;
    const auto x = std::ranges::unique(cp);
    cp.erase(x.begin(), x.end());
    for(const auto &e: v)  {
        ret.emplace_back(std::ranges::lower_bound(cp, e) - cp.cbegin());
    }
    return ret;
}
}
std::ostream &operator<<(std::ostream &os, const std::vector<int> &v) {
    os << v.front();
    for(const auto i: std::views::iota(1, std::ssize(v))) {
        os << ' ' << v[i];
    }
    return os;
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int n, q;
    std::cin >> n >> q;
    std::vector<int> x(n);
    for(auto &e: x) {
        std::cin >> e;
    }
    std::ranges::sort(x);
    const auto &y = man::press(x);
    if(n + std::ssize(y) > q) {
        std::cout << "No\n";
        std::exit(0);
    }
    std::cout << "Yes\n";
    std::vector<std::vector<int>> ret;
    for(const auto &e: x) {
        const std::vector z = {1, static_cast<int>(std::ranges::lower_bound(x, e) - x.cbegin()) + 1, e};
        ret.emplace_back(z);
    }
    for(const auto &e: y) {
        const std::vector z = {2, e + 1};
        ret.emplace_back(z);
    }
    for([[maybe_unused]] const auto _: iota(0, q - std::ssize(ret))) {
        const std::vector z = {1, 1, man::VvyLw};
        ret.emplace_back(z);
    }
    for(const auto &e: ret) {
        std::cout << e << '\n';
    }
}