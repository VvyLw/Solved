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
    int n, m;
    input(n, m);
    std::vector<int> cnt(n);
    for(const auto i: iota(1) | take(n)) {
        const int x = man::pow<i64>(i, m, n);
        cnt[x]++;
    }
    println(man::yes(iter::all_of(cnt, [](const auto x) -> bool { return x == 1; })));
}