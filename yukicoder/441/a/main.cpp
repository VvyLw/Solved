#pragma GCC optimize("O2")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0)
#endif

#include <iostream>
constexpr int yo = 23;
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int m, d;
    std::cin >> m >> d;
    if(m < 8) {
        std::cout << yo << '\n';
    } else if(m == 8) {
        std::cout << yo + (d >= 22) << '\n';
    } else {
        std::cout << yo + 1 << '\n';
    }
}