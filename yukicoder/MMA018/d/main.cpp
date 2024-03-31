#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <atcoder/modint>
typedef atcoder::modint mint;
int main() {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	int n, p, q, cnt = 0;
	std::cin >> n >> p >> q;
	mint::set_mod(p);
	std::vector<int> a(n);
	for(auto &el: a) {
		std::cin >> el;
	}
    std::ranges::sort(a);
	for(int i = 0; i < n; ++i) {
		for(int j = i; ++j < n;) {
			for(int k = j; ++k < n;) {
				if(std::ranges::binary_search(a, (mint(9).pow(a[i]) + mint(7).pow(a[j]) + mint(5).pow(a[k]) + q).val())) {
                    cnt++;
                }
			}
		}
	}
	std::cout << cnt << '\n';
}