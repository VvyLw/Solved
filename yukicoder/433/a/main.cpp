#include <iostream>
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int a, b;
    std::cin >> a >> b;
    if(b < 0) {
        b *= -1;
    }
    a %= b;
    if(a < 0) {
        a += b;
    }
    std::cout << a << '\n';
}