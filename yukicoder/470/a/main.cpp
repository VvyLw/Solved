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

constexpr int n = 3;

inline void VvyLw::solve() noexcept {   
	for(const auto i: iota(0, 1 << n)) {
        man::vec::zhl a(n);
        for(const auto j: iota(0, n)) {
            a[j] = i >> j & 1;
        }
        if(!(a[0] & a[1]) & !a[2] != !a[0] & !(a[1] & a[2])) {
            return println(a);
        }
    }
}