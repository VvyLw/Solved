#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::ranges;
    using namespace std::views;
    int n;
    std::cin >> n;
    std::vector<std::string> a(n), b(n, std::string(n, '.'));
    for(auto &s: a) {
        std::cin >> s;
    }
    for(const auto i: iota(0, n)) {
		for(const auto j: iota(0, n)) {
			const int d = std::min({i + 1, j + 1, n - i, n - j});
			int x = i, y = j;
			for([[maybe_unused]] const auto _: iota(0, d % 4)) {
				const int p = y, q = n - 1 - x;
				x = p;
				y = q;
			}
			b[x][y] = a[i][j];
		}
	}
    for(const auto &s: b) {
        std::cout << s << '\n';
    }
}