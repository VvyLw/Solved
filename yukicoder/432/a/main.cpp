#include <iostream>
#include <vector>
#include <ranges>
int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> a;
    bool ok=true;
    for(const auto i: std::views::iota(0, n)) {
        if(ok && s[i] == 'o') {
            a.emplace_back(i + 1);
            ok = false;
        } else if(s[i] == 'x') {
            ok = true;
        }
    }
    const int m = std::ssize(a);
    std::cout << m << '\n';
    if(m == 0) {
        std::cout << '\n';
    } else {
        for(const auto i: std::views::iota(0, m)) {
            std::cout << a[i] << " \n"[i + 1 == m];
        }
    }
}