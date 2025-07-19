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
	std::string s;
	input(s);
	man::vec::zhl a;
	for(const auto i: iota(0, std::ssize(s))) {
		if(s[i] == '#') {
			a.emplace_back(i + 1);
		}
	}
	const int n = std::ssize(a);
	assert(n % 2 == 0);
	for(const auto i: iota(0, n / 2)) {
		std::cout << a[2 * i] << ',' << a[2 * i + 1] << '\n';
	}
}