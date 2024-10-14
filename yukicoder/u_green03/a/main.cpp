#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <ranges>
namespace man {
constexpr inline std::string yes(const bool b) noexcept {
	return b ? "Yes" : "No";
}
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::ranges;
    using namespace std::views;
    int n, m, k;
	std::cin >> n >> m >> k;
	std::cout << man::yes(n >= m + k) << '\n';
}