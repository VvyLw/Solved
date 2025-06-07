/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"

int main() {
	VvyLw::wa_haya_exe();
	now(start);
	int T = 1;
	// std::cin >> T;
	REP(T) {
		VvyLw::solve();
	}
	now(stop);
	time(start, stop);
}

// --------------------------------------------------------------------------------------------------------------


void VvyLw::solve() {
	int n;
	std::cin >> n;
	man::vec::vi a(n);
	std::cin >> a;
	iter::sort(a, std::greater<>());
	dump(a);
	for(const auto i: iota(1) | take(n) | reverse) {
		if(a[i - 1] >= i) {
			std::cout << i << '\n';
			return;
		}
	}
	std::cout << "0\n";
}