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
    int n, ret = 0;
    input(n);
    man::vec::zhl a(n), b(n);
    input(a, b);
    for(const auto i: iota(0, n)) {
        ret += std::max(0LL, a[i] - b[i]);
    }
    println(ret);
}