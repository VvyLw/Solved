#pragma GCC optimize("O2")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <cstdint>
#include <bit>
namespace man {
constexpr inline int64_t pow2(int m) noexcept {
    int64_t base = 2, ret = 1;
	while(m) {
		if(m & 1) {
            ret *= base;
        }
		base *= base;
        m >>= 1;
	}
	return ret;
}
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    uint64_t n;
    std::cin >> n;
    const int m = std::popcount(n);
    std::cout << man::pow2(m) - 2 << '\n';
}