#include <iostream>
#include "C++/LazySegmentTree.hpp"
int main() {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<int64_t> a(n), b(m);
	for(auto &el: a) {
		std::cin >> el;
	}
	for(auto &el: b) {
		std::cin >> el;
	}
	RUQRMX<int64_t> seg(a, 0);
	for(auto el: b) {
		int64_t c = seg[el];
		seg.set(el, 0);
        const int64_t q = c / n;
		c %= n;
        seg.update(0, n, q);
        if(++el + c <= n) {
            seg.update(el, el + c, 1);
        } else {
            seg.update(el, n, 1);
            seg.update(0, el + c - n, 1);
        }
	}
	std::cout << seg << '\n';
}