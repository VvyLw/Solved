#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
constexpr int INF = 1 << 30;
constexpr auto range = std::views::iota;
template <class T> constexpr inline int chmin(T& a, const T& b) noexcept {
	if(a > b) {
		a = b;
		return 1;
	}
	return 0;
}
int main() {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> s(n);
	for(auto &t: s) {
		std::cin >> t;
	}
	int ans = INF;
	for(const auto &i: range(0, 1 << n)) {
		std::vector<int> vis(m);
		for(const auto &j: range(0, n)) {
			if(i >> j & 1) {
				for(const auto &k: range(0, m)) {
					vis[k] |= s[j][k] == 'o';
				}
			}
		}
		if(std::ranges::all_of(vis, [](const int b) -> int { return b; })) {
			chmin(ans, __builtin_popcount(i));
		}
	}
	std::cout << ans << '\n';
}