#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <ranges>
#include "C++/ds/DualSegmentTree.hpp"
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::ranges;
    using namespace std::views;
    int n, q;
    std::cin >> n >> q;
    DualSegTree<int> seg(n, [](const int a, const int b) -> int { return a ^ b; }, 0);
    for(const auto &i: iota(0, n)) {
        int a;
        std::cin >> a;
        seg.apply(i, i + 1, a);
    }
    // for(const auto i: iota(0, n)) {
    //     std::cout << seg[i] << " \n"[i + 1 == n];
    // }
    for([[maybe_unused]] const auto _: iota(0, q)) {
        int l, r;
        std::cin >> l >> r;
        seg.apply(--l, r, 1);
    }
    for(const auto i: iota(0, n)) {
        std::cout << seg[i] << " \n"[i + 1 == n];
    }
}