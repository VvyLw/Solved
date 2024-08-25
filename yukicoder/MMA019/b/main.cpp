#pragma GCC optimize("O2")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <valarray>
#include <ranges>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::valarray<int> cnt(n + 1);
    for([[maybe_unused]] const auto _: std::views::iota(0, n)) {
        int a;
        std::cin >> a;
        cnt[a]++;
    }
    std::cout << (cnt / 2).sum() << '\n';
}