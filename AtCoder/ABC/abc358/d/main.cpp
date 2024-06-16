#include <iostream>
#include <map>
#include <ranges>
constexpr auto range = std::views::iota;
int main() {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::map<int, int> cnt;
	for([[maybe_unused]] const auto _: range(0, n)) {
		int a;
		std::cin >> a;
		cnt[a]++;
	}
	int64_t ans = 0;
	for([[maybe_unused]] const auto _: range(0, m)) {
		int b;
		std::cin >> b;
		const auto it = cnt.lower_bound(b);
		if(it == cnt.cend()) {
			std::cout << -1 << '\n';
			return 0;
		}
		ans += it -> first;
		if(--it -> second == 0) {
			cnt.erase(it);
		}
	}
	std::cout << ans << '\n';
}