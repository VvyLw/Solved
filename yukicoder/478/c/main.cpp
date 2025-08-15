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
    std::vector<man::pav::str> p(n);
    input(p);
    if(iter::none_of(p, [](const auto &z) -> bool { return z.first == "a"; })) {
        return println("No");
    }
    iter::sort(p);
    dump(p);
    int lim = INF;
    for(const auto &[x, y]: p) {
        const int a = iter::count(y, 'a'), m = std::ssize(y);
        if(lim != INF) {
            const int b = iter::count(x, 'b');
            if(b <= lim && (a > 0 || m - a > b)) {
                return println("Yes");
            }
        } else {
            if(a > 1 || (a == 1 && m - a > 0)) {
                return println("Yes");
            }
        }
        if(a == 0) {
            man::chmin(lim, m);
        }
    }
    println("No");
}