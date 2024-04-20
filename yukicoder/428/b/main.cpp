#include <iostream>
#include <vector>
#include <algorithm>
#include <atcoder/modint>
typedef atcoder::modint998244353 mint;
int main() {
	int n;
	std::cin >> n;
	std::vector<int64_t> a(n);
	for(auto &el: a) {
		std::cin >> el;
	}
	std::ranges::sort(a);
	mint res = 0;
	for(const auto &x: a) {
		res = 10 * res + x;
	}
	std::cout << res.val() << '\n';
}