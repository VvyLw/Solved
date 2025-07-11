/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/ds/SegmentTree.hpp"

int main() {
    now(start);
    VvyLw::wa_haya_exe();
    now(stop);
    time(start, stop);
}

// --------------------------------------------------------------------------------------------------------------


inline void VvyLw::solve() noexcept {
    int q, sz = 0;
    input(q);
    man::SegTree<int> seg(q, [](const int a, const int b) -> int { return std::max(a, b); }, 0);
    REP(q) {
        int t, x;
        input(t, x);
        if(t == 1) {
            seg.update(sz++, x);
        } else {
            println(seg.query(sz - x, sz));
        }
    }
}