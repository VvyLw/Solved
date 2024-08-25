#pragma GCC optimize("O2")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <valarray>
#include <algorithm>
#include <numeric>
#include <ranges>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    std::valarray<int> a(n), b(n), c(n);
    for(auto &e: a) {
        std::cin >> e;
    }
    for(auto &e: b) {
        std::cin >> e;
    }
    for(auto &e: c) {
        std::cin >> e;
    }
    std::valarray<int> d = b - c, id(n);
    std::iota(std::begin(id), std::end(id), 0);
    dump(d);
    std::ranges::sort(id, [&](const int i, const int j) -> bool {
        return d[i] > d[j];
    });
    dump(id);
    std::valarray<int64_t> ret(n);
    for(const auto &i: std::views::iota(0, n)) {
        const int j = id[i];
        ret[i] = a[j] + (i < k ? b[j] : c[j]);
    }
    dump(ret);
    std::cout << ret.sum() << '\n';
}