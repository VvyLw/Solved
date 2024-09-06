#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <vector>
#include <ranges>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    if(n % k) {
        std::cout << "-1\n";
        std::exit(0);
    }
    const int p = n / k, q = n - p;
    std::vector<int> a(n);
    for(const auto &i: std::views::iota(0, p)) {
        a[i] = 1;
    }
    for(const auto &i: std::views::iota(0, q)) {
        a[p + i] = i + 2;
    }
    dump(a);
    for(const auto &i: std::views::iota(0, n)) {
        std::cout << a[i] << " \n"[i + 1 == n];
    }
}