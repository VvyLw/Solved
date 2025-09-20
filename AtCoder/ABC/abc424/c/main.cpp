/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/graph/Graph.hpp"

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
	man::graph<false> g(n + 1, 0);
	for(const auto i: iota(0, n)) {
		int a, b;
		input(a, b);
		g.add(a, i + 1);
		g.add(b, i + 1);
	}
	const auto d = g.all_dist(0);
	dump(d);
	println(iter::count_if(d, [](const auto &e) -> bool { return e > 0; }));
}