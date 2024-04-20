#include <iostream>
#include <vector>
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::string> a(n), b(n * k, std::string(n * k, '.'));
    for(auto &el: a) {
        std::cin >> el;
    }
    for(int i = 0; i < k * n; ++i) {
        for(int j = 0; j < k * n; ++j) {
            b[i][j] = a[i / k][j / k];
        }
        std::cout << b[i] << '\n';
    }
}