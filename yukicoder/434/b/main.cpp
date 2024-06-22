#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <cmath>
#include <ranges>
#include <C++/core/io/debug_print.hpp>
constexpr int dx[4] = {0, 0, -1, 1};
constexpr int dy[4] = {-1, 1, 0, 0};
constexpr auto d = std::views::iota(0, 4);
template <class T> constexpr inline bool chmax(T &a, const T &b) noexcept { if(a < b){ a = b; return true; } return false; }
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    const auto sqr = [](const int x) -> int64_t { return x * x; };
    long double res = 0;
    for(const auto a: d) {
        const int p1 = x1 + dx[a], q1 = y1 + dy[a];
        for(const auto b: d) {
            const int p2 = x2 + dx[b], q2 = y2 + dy[b];
            for(const auto c: d) {
                const int p3 = x3 + dx[c], q3 = y3 + dy[c];
                const long double x = std::sqrt(sqr(p1 - p2) + sqr(q1 - q2)), y = std::sqrt(sqr(p2 - p3) + sqr(q2 - q3)), z = std::sqrt(sqr(p3 - p1) + sqr(q3 - q1));
                const long double s = (x + y + z) / 2;
                if(chmax(res, std::sqrt(s * (s - a) * (s - b) * (s - c)))) {
                    dump(p1, q1, p2, q2, p3, q3);
                }
            }
        }
    }
    std::cout << res << '\n';
}