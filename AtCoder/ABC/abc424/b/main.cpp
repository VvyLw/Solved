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
	int n, m, k;
	input(n, m, k);
	man::vec::zhl p(n), ret;
	REP(k) {
		int a, b;
		input(a, b);
		if(++p[a - 1] == m) {
			ret.emplace_back(a);
		}
	}
	println(ret);
}