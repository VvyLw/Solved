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
    int n;
    input(n);
    man::vec::zhl a(n);
    input(a);
    iter::sort(a, std::greater());
    int ret = a[1];
    for(const auto i: iota(1, n - 1)) {
        for(const auto j: iota(i + 1, n)) {
            man::chmax(ret, man::mod(a[0], a[i] + a[j]));
        }
    }
    println(ret);
}