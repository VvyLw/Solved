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

constexpr int n = 100;

inline void VvyLw::solve() noexcept {
    println(n - 1);
    man::graph<false> g(n, 0);
    for(const auto i: iota(0, n - 1)) {
        g.add(i, i + 1);
    }
    for(const auto &e: g.get_edge()) {
        println(e.src + 1, e + 1);
    }
}