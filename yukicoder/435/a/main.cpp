#include <iostream>
#include <array>
#include <algorithm>
constexpr std::array<int64_t, 7> a = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328};
int main() {
    int64_t n;
    std::cin >> n;
    std::cout << (std::ranges::binary_search(a, n) ? "Yes" : "No") << '\n';
}