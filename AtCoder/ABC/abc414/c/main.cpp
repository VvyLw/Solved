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

constexpr int MAX = 1e6;

inline void VvyLw::solve() noexcept {
	int a;
	i64 n, ret = 0;
	input(a, n);
	std::unordered_set<i64> s;
	const auto fn = [](const i64 &x, const int p = 0) -> i64 {
		const std::string s = std::to_string(x);
		auto t = s;
		iter::reverse(t);
		return man::to_ten(s + t.substr(p));
	};
	const auto ok = [&n, &a](const i64 &x) -> bool {
		return x <= n && man::is_palindrome(man::ten_to(x, a));
	};
	for(const auto i: iota(1) | take(MAX)) {
		for(const auto j: iota(0, 2)) {
			const auto x = fn(i, j);
			if(ok(x)) {
				s.emplace(x);
			}
		}
	}
	println(man::sum(s));
}