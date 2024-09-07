#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <ranges>
namespace man {

}
int main() {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	int h, w, q;
	std::cin >> h >> w >> q;
	std::vector<std::set<int>> x(h), y(w);
	for(const auto &i: std::views::iota(0, h)) {
		for(const auto &j: std::views::iota(0, w)) {
			x[i].emplace(j);
			y[j].emplace(i);
		}
 	}
	const auto del = [&](const int r, const int c) -> void {
		x[r].erase(c);
		y[c].erase(r);
	};
	for([[maybe_unused]] const auto _: std::views::iota(0, q)) {
		int r, c;
		std::cin >> r >> c;
		--r, --c;
		if(x[r].contains(c)) {
			del(r, c);
		} else {
			{
				const auto it = x[r].lower_bound(c);
				if(it != x[r].cbegin()) {
					del(r, *std::prev(it));
				}
				if(it != x[r].cend()) {
					del(r, *it);
				}
			}
			{
				const auto it = y[c].lower_bound(r);
				if(it != y[c].cbegin()) {
					del(*std::prev(it), c);
				}
				if(it != y[c].cend()) {
					del(*it, c);
				}
			}
		}
		dump(x);
	}
	std::cout << std::accumulate(x.cbegin(), x.cend(), 0, [](const int acc, const auto s) -> int {
		return acc + std::ssize(s);
	}) << '\n';
}