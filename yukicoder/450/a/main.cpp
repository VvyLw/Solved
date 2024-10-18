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
#include <cstdint>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    uint64_t n;
    std::cin >> n;
    std::cout << n * (n + 1) / 2 << '\n';
}