/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include <atcoder/math>

int main() {
    now(start);
    VvyLw::wa_haya_exe();
    now(stop);
    time(start, stop);
}

// --------------------------------------------------------------------------------------------------------------


inline void VvyLw::solve() noexcept {
    i64 n;
    int p, q, r, a, b, c;
    input(n, p, q, r, a, b, c);
    man::vec::zhl s{a, b}, t{p, q};
    const auto &[y, z] = atcoder::crt(s, t);
    man::vec::zhl u{c, y}, v{r, z};
    const auto &[x, m] = atcoder::crt(u, v);
    println(n >= x ? (n - x) / m + 1 : 0);
}