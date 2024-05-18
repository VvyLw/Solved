#include <iostream>
#include <vector>
#include <algorithm>
inline void solve() {
    int l, n;
    std::cin >> l >> n;
    std::vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i) {
        int z;
        std::cin >> z;
        x[i] = std::min(z, l - z);
        y[i] = std::max(z, l - z);
    }
    std::cout << *std::max_element(x.begin(), x.end()) << ' ' << *std::max_element(y.begin(), y.end()) << '\n';
}
int main() {
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
}