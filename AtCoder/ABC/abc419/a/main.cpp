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
	std::unordered_map<std::string, std::string> m{
		{"red", "SSS"},
		{"blue", "FFF"},
		{"green", "MMM"}
	};
	println(m.contains(s) ? m[s] : "Unknown");
}