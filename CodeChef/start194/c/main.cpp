/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"

int main() {
    now(start);
    VvyLw::wa_haya_exe<multi>();
    now(stop);
    time(start, stop);
}

// --------------------------------------------------------------------------------------------------------------


inline void VvyLw::solve() noexcept {
    int n, ret = -INF;
    input(n);
    man::vec::zhl a(n);
    input(a);
    for(const auto x: iota(1) | take(100)) {
        int tmp = 0;
        for(const auto i: iota(0, n)) {
            tmp -= 30 * x;
            tmp += 50 * std::min<int>(x, a[i]);
        }
        man::chmax(ret, tmp);
    }
    println(ret);
}