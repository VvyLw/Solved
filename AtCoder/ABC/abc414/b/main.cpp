/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/other/runlength.hpp"

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
	i64 len = 0;
	man::vec::V<man::pav::P<char, int>> p(n);
	for(auto &q: p) {
		input(q);
		len += q.second;
		if(len > 100) {
			return println("Too Long");
		}
	}
	println(man::rle_rev(p));
}