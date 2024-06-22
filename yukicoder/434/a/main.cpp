#include <iostream>
int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    b += 31;
    b -= a;
    if(b >= c) {
        std::cout << 1 << '\n';
    } else if(b >= d) {
        std::cout << 2 << '\n';
    } else {
        std::cout << 3 << '\n';
    }
}