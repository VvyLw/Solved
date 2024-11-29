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

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int64_t n, m;
    std::cin >> n >> m;
    if(n == 0 || m == 0) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n" << n * m << ' ' << m - 1 << '\n';
    }
}