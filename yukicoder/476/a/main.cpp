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
    int n;
    input(n);
    man::vec::zhl a(n);
    input(a);
    const int l = man::sum(a) / n;
    println(iter::count_if(a, [&l](const auto &e) -> bool { return e >= (l + 100); }));
}