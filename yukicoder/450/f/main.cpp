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
#include <atcoder/fenwicktree>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int n, q, l0;
    std::cin >> n >> q >> l0;
    atcoder::fenwick_tree<int64_t> cnt(1 << 18), bit(1 << 18);
    for([[maybe_unused]] const auto _: iota(0, n)) {
        int a;
        std::cin >> a;
        cnt.add(a, 1);
        bit.add(a, a);
    }
    bool none = true;
    for([[maybe_unused]] const auto _: iota(0, q)) {
        int t;
        std::cin >> t;
        if(t == 1) {
            int l;
            std::cin >> l;
            cnt.add(l, 1);
            bit.add(l, l);
        } else if(t == 2) {
            none = false;
            int l, r;
            std::cin >> l >> r;
            r++;
            std::cout << cnt.sum(l, r) << ' ' << bit.sum(l, r) << '\n';
        } else {
            int m;
            std::cin >> m;
        }
    }
    if(none) {
        std::cout << "Not Found!\n";
    }
}