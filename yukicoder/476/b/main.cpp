/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/graph/Graph.hpp"

int main() {
    now(start);
    VvyLw::wa_haya_exe();
    now(stop);
    time(start, stop);
}

// --------------------------------------------------------------------------------------------------------------


inline void VvyLw::solve() noexcept {
    int n, k = 0;
    input(n);
    man::vec::zhl p(n), q;
    input(p);
    man::graph<false> g(n, 0);
    for(const auto i: iota(0, n)) {
        if(p[i] == 0) {
            k = i;
            continue;
        }
        g.add(p[i] - 1, i);
    }
    const auto d = g.all_dist(k = 2);
    dump(d);
    println(iter::count_if(d, [](const auto &e) -> bool { return e >= 2; }));
}