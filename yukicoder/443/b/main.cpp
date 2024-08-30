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
    std::string a;
    int b;
    std::cin >> a >> b;
    const int n = a.size();
    std::valarray<int> v(n);
    for(const auto &i: std::views::iota(0, n)) {
        v[i] = a[i] - '0';
    }
    const auto vtoi = [](const std::valarray<int> &v) -> int {
        int64_t x = 0;
        for(const auto &e: v) {
            x += e;
            x *= 10;
        }
        x /= 10;
        return x;
    };
    bool ok = false;
    const auto rec = [&](const auto &f, const int d) -> void {
        if(d == n) {
            dump(vtoi(v));
            ok |= vtoi(v) == b;
            return;
        }
        for(const auto &i: std::views::iota(0, v[d] + 1)) {
            v[d] = i;
            f(f, d + 1);
        }
    };
    rec(rec, 0);
    std::cout << (ok ? "Yes\n" : "No\n");
}