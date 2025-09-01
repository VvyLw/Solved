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
	int x, y;
	input(x, y);
	std::array<i64, 10> a{};
	a[0] = x, a[1] = y;
	const auto f = [](const i64 x, const i64 y) -> i64 {
		auto s = std::to_string(x + y);
		iter::reverse(s);
		return man::to_ten(s);
	};
	for(const auto i: iota(0, 8)) {
		a[i + 2] = f(a[i + 1], a[i]);
	}
	dump(a);
	println(a.back());
}