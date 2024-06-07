#include <iostream>
int main() {
    int n;
    std::cin >> n;
    std::string ans;
    ans += std::string(n / 720, 'C');
    n %= 720;
    ans += std::string(n / 360, 'M');
    n %= 360;
    ans += std::string(n / 180, 'S');
    n %= 180;
    ans += std::string(n / 30, 'R');
    n %= 30;
    ans += std::string(n / 6, 'o');
    n %= 6;
    ans += std::string(n, '.');
    std::cout << ans << '\n';
}