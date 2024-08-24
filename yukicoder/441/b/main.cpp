#pragma GCC optimize("O2")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0)
#endif

#include <iostream>
#include <cassert>
constexpr int dx[] = {0, 0, -1, 1};
constexpr int dy[] = {-1, 1, 0, 0};
int main() {
    int n;
    std::cin >> n;
    std::pair<int, int> a, b, c;
    std::cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    assert(n > 4);
    std::cout << 4 << '\n';
    for(int i = 0; i < 4; ++i) {
        std::cout << c.first + dx[i] << ' ' << c.second + dy[i] << '\n';
    }
}