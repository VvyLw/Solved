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
#include <vector>
namespace man {
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr inline bool scope(const int l, const int x, const int r) noexcept {
    return l <= x && x < r;
}
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int h, w, si, sj, gi, gj, cnt = 0;
    std::cin >> h >> w >> si >> sj >> gi >> gj;
    si--, sj--, gi--, gj--;
    std::vector vis(h, std::vector(w, false));
    const auto dfs = [&](const auto &f, const int x, const int y) -> void {
        if(x == gi && y == gj) {
            cnt++;
            return;
        }
        for(const auto i: iota(0, 4)) {
            const int nx = x + man::dx[i], ny = y + man::dy[i];
            if(man::scope(0, nx, h) && man::scope(0, ny, w)) {
                if(vis[nx][ny]) {
                    continue;
                }
                int z = 0;
                for(const auto j: iota(0, 4)) {
                    const int mx = nx + man::dx[j], my = ny + man::dy[j];
                    if(man::scope(0, mx, h) && man::scope(0, my, w)) {
                        if(vis[mx][my]) {
                            z++;
                        }
                    }
                }
                if(z == 1) {
                    vis[nx][ny] = true;
                    f(f, nx, ny);
                }
                vis[nx][ny] = false;
            }
        }
    };
    vis[si][sj] = true;
    dfs(dfs, si, sj);
    std::cout << cnt << '\n';
}