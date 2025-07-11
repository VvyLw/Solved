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
    man::vec::str s(n), t(n);
    std::unordered_map<std::string, int> pat;
    for(const auto i: iota(0, n)) {
        input(s[i], t[i]);
        pat[s[i]]++;
        pat[t[i]]++;
    }
    bool ok = true;
    for(const auto i: iota(0, n)) {
        ok &= pat[s[i]] == 1 || pat[t[i]] == 1;
    }
    println(man::yes(ok));
}