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
#include <algorithm>
#include <atcoder/modint>
namespace man {
using mint = atcoder::modint998244353;
const std::string look = "LRU";
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector dp(n, std::vector(3, man::mint(0)));
    auto &init = dp.front();
    const auto id = man::look.find(s.front());
    dump(id);
    if(id == std::string::npos) {
        std::ranges::fill(init, man::mint(1));
    } else {
        init[id] = man::mint(1);
    }
    for(const auto i: iota(0, n - 1)) {
        if(s[i + 1] == 'L') {
            dp[i + 1][0] = dp[i][0] + dp[i][2];
        } else if(s[i + 1] == 'R') {
            dp[i + 1][1] = dp[i][0] + dp[i][1] + dp[i][2];
        } else if(s[i + 1] == 'U') {
            dp[i + 1][2] = dp[i][0] + dp[i][1] + dp[i][2];
        } else {
            dp[i + 1][0] = dp[i][0] + dp[i][2];
            dp[i + 1][1] = dp[i][0] + dp[i][1] + dp[i][2];
            dp[i + 1][2] = dp[i][0] + dp[i][1] + dp[i][2];
        }
    }
    const auto &ret = dp.back();
    std::cout << std::accumulate(ret.cbegin(), ret.cend(), man::mint(0)).val() << '\n';
}