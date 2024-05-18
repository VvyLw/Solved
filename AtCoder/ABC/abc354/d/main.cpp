#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
#include <ranges>
#if local
//https://gist.github.com/naskya/1e5e5cd269cfe16a76988378a60e2ca3
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) static_cast<void>(0)
#endif
constexpr inline int mod(int a, const int b) noexcept {
    a %= b;
    return a < 0 ? a + b : a;
}
constexpr inline int64_t ceil(const int64_t a, const int b) noexcept { return (int64_t) std::ceil((long double) a / b); }
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int64_t w = c - a, h = d - b, s = (w / 4) * (h / 2) * 8;
    std::array<int, 4> x = {2, 1, 0, 1}, y = {1, 2, 1, 0};
    std::ranges::rotate(x, x.begin() + mod(a, 4));
    std::ranges::rotate(y, y.begin() + mod(a, 4));
    if(mod(b, 2)) {
        x.swap(y);
    }
	dump(x, y);
	for(const auto i: std::views::iota(0, w % 4)) {
		s += x[i] * ceil(h, 2);
		s += y[i] * ceil(h - 1, 2);
		dump(s);
	}
	if(h & 1) {
		s += (w / 4) * 4;
	}
    std::cout << s << '\n';
}