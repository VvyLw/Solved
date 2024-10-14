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
namespace man {
constexpr inline void chmax(int &a, const int b) noexcept {
    if(a < b) {
        a = b;
    }
}
inline std::string yes(const bool b) noexcept {
    return b ? "Yes" : "No";
}
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int n, s, b, alt;
    std::cin >> n >> s >> b;
    bool ok = true;
    const int64_t lim = (int64_t) s * b;
    for(const auto i: iota(0, n)) {
        int h;
        std::cin >> h;
        if(i == 0) {
            alt = h;
            continue;
        }
        ok &= h - alt <= lim;
        man::chmax(alt, h);
    }
    std::cout << man::yes(ok) << '\n';
}