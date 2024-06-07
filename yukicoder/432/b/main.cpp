#include <iostream>
#include <vector>
#include <cmath>
#include <ranges>
constexpr int INF = 1 << 30;
int main() {
    int n, k, ok, ng;
    std::cin >> n >> k;
    std::vector<int> a(n), ans;
    for(auto &e: a) {
        std::cin >> e;
    }
    ok = INF;
    ng = -1;
    while(std::abs(ok - ng) > 1) {
        const int mid = (ok + ng) / 2;
        int cnt = 0;
        for(const auto &e: a) {
            if(e <= mid) {
                cnt++;
            }
        }
        if(cnt >= k) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    bool in = true;
    for(int i = 0; i < n; ++i) {
        if(in && a[i] > ok) {
            ans.emplace_back(i + 1);
            in = false;
        } else if(a[i] <= ok) {
            in = true;
        }
    }
    const int m = std::ssize(ans);
    std::cout << m << '\n';
    if(m == 0) {
        std::cout << '\n';
    } else {
        for(int i = 0; i < m; ++i) {
            std::cout << ans[i] << " \n"[i + 1 == m];
        }
    }
}