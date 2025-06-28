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
	std::string s, t;
	input(s, t);
	const int n = std::ssize(s);
	bool ok = true;
	for(const auto i: iota(1, n)) {
		if(man::isupper(s[i])) {
			ok &= t.find(s[i - 1]) != std::string::npos;
		}
	}
	println(man::yes(ok));
}