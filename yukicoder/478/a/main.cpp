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
    int h, w;
    input(h, w);
    std::string s, t;
    for(const auto i: iota(0, w)) {
        s += i % 2 == 0 ? 'O' : 'X';
        t += i % 2 != 0 ? 'O' : 'X';
    }
    for(const auto i: iota(0, h)) {
        println((i / 2) % 2 == 0 ? s : t);
    }
}