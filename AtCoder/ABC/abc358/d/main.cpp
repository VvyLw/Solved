#include <iostream>
#include <set>
#include <ranges>
constexpr auto range = std::views::iota;
int main() {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::multiset<int> a;
	for([[maybe_unused]] const auto _: range(0, n)) {
		int e;
		std::cin >> e;
		a.emplace(e);
	}
	int64_t ans = 0;
	for([[maybe_unused]] const auto _: range(0, m)) {
		int b;
		std::cin >> b;
		const auto it = a.lower_bound(b);
		if(it == a.cend()) {
			std::cout << -1 << '\n';
			return 0;
		}
		ans += *it;
		a.erase(it);
	}
	std::cout << ans << '\n';
}