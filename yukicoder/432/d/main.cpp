#include <iostream>
int main() {
    int a, b, h, w;
    std::cin >> a >> b >> h >> w;
    if((a < b && h < w) || (a > b && h > w)) {
        std::cout << "Non-rotating\n";
    } else if((a < b && h > w) || (a > b && h < w)) {
        std::cout << "Rotating\n";
    } else {
        std::cout << "Same\n";
    }
}