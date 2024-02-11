#include <iostream>
#include <cmath>
void solve() {
    char c;
    int64_t n1, n2;
    std::cin >> c >> n1;
    if(c == 'B') {
        n1 *= -1;
    }
    std::cin >> c >> n2;
    if(c == 'B') {
        n2 *= -1;
    }
    if(n1 * n2 > 0) {
        std::cout << std::abs(n1 - n2) << '\n';
	} else {
        std::cout << std::max(0L, std::abs(n1 - n2) - 1) << '\n';
	}
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
}