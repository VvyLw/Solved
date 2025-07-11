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
    man::vec::str s(3);
    input(s);
    for(const auto &t: s) {
        print(static_cast<char>(std::toupper(t.front())));
    }
    println();
}