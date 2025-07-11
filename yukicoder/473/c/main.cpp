/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"

int main() {
    now(start);
    VvyLw::wa_haya_exe();
    now(stop);
    time(start, stop);
}

// --------------------------------------------------------------------------------------------------------------


inline void VvyLw::solve() noexcept {
    int n, q;
    input(n);
    man::vec::zhl a(n);
    input(a);
    iter::sort(a);
    input(q);
    REP(q) {
        int x, k;
        input(x, k);
        println(man::yes(man::count<i64>(a, x) >= k));
    }
}