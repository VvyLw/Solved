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
#include <set>
#include <algorithm>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), cnt(m + 1), ret(n);
    for(auto &e: a) {
        std::cin >> e;
    }
    std::ranges::transform(a, a.begin(), [m](const int x) -> int { return std::min(m, x); });
    dump(a);
    if(m == 0) {
        for(const auto i: iota(0, n)) {
            std::cout << n - i << '\n';
        }
        std::exit(0);
    }
    std::set<int> mx;
    for(const auto i: iota(0, m + 2)) {
        mx.emplace(i);
    }
    for(int l = 0, r = 0; r < n; ++r) {
        cnt[a[r]]++;
        mx.erase(a[r]);
        while(l <= r) {
            if(*mx.cbegin() < m) {
                ret[r - l]++;
                break;
            }
            if(--cnt[a[l]] == 0) {
                mx.emplace(a[l]);
            }
            l++;
        }
    }
    for(const auto i: iota(1, n) | reverse) {
        ret[i - 1] += ret[i];
    }
    dump(ret);
    for(const auto i: iota(0, n)) {
        std::cout << n - (i + ret[i]) << '\n';
    }
}