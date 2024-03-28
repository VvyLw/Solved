#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <C++/core/io/debug_print.hpp>
template <class T, class U> inline bool chmin(T& a, const U& b){ if(a>b){ a=b; return 1; } return 0; }
template <class T> inline std::vector<T> div(const T n) {
    std::vector<T> d;
    for(long i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            d.emplace_back(i);
            if(i * i != n) {
                d.emplace_back(n / i);
            }
        }
    }
    std::ranges::sort(d);
    return d;
}
inline void solve() {
    int n, ans;
    std::string s;
    std::cin >> n >> s;
    ans = n;
    const auto d = div(n);
    for(const auto &el: d) {
        std::unordered_map<std::string, int> m;
        for(int i = 0; i < n; i += el) {
            m[s.substr(i, el)]++;
        }
        if(m.size() == 1) {
            chmin(ans, el);
        }
        if(m.size() == 2) {
            const std::string a = m.cbegin() -> first, b = next(m.cbegin()) -> first;
            assert(a.size() == b.size());
            int cnt = 0;
            for(size_t i = 0; i < a.size(); ++i) {
                if(a[i] != b[i]) {
                    cnt++;
                }
            }
            if(cnt == 1 && (m[a] == 1 || m[b] == 1)) {
                chmin(ans, el);
            }
        }
    }
    std::cout << ans << '\n';
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
}