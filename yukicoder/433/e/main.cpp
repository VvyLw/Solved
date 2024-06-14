#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
inline void solve() {
    int n, cnt = 0;
    std::cin >> n;
    std::cout << (std::abs(n) == 1 ? "Yes\n" : "No\n");
    auto m = boost::multiprecision::cpp_int(n) * n * n * n + 4;
    while(m % 10 == 0) {
        m /= 10;
        cnt++;
    }
    std::cout << cnt << '\n';
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
}