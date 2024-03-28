#include <iostream>
#include <vector>
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(2 * n, std::string(2 * n, '.'));
    for(int i = 0; i < 2 * n; ++i) {
        for(int j = 0; j < 2 * n; ++j) {
            if(i / 2 % 2 == 0 && j / 2 % 2 == 0) {
                s[i][j] = '#';
            }
            if(i / 2 % 2 == 1 && j / 2 % 2 == 1) {
                s[i][j] = '#';
            }
        }
    }
    for(const auto &t: s) {
        std::cout << t << '\n';
    }
}
int main() {
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
}