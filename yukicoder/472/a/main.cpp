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
    int n, x;
    input(n);
    man::vec::zhl a(n);
    input(a, x);
    man::vec::zhl2 ret(4, man::vec::zhl(4, x));
    println("Yes");
    for(const auto &v: ret) {
        println(v);
    }
}