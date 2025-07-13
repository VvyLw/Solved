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
	int a;
	i64 n, ret = 0;
	input(a, n);
	std::unordered_set<i64> s;
	const auto fn = [](const i64 &x, const int p = 0) -> i64 {
		std::string s = std::to_string(x);
		const auto t = s.substr(0, std::ssize(s) - p);
		iter::reverse(s);
		return man::to_ten(t + s);
	};
	const auto ok = [&n, &a](const i64 &x) -> bool {
		return x <= n && man::is_palindrome(man::ten_to(x, a));
	};
	for(const auto i: iota(1) | take(1000000LL)) {
		const i64 x = fn(i), y = fn(i, 1);
		if(ok(x)) {
			s.emplace(x);
		}
		if(ok(y)) {
			s.emplace(y);
		}
	}
	println(man::sum(s));
}