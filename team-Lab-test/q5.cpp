#include <iostream>
#include <cassert>
#include <algorithm>
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    std::string s = "0123456789";
    assert(std::ranges::is_sorted(s));
    do {
        const int x = std::stoi(s.substr(0, 6)), y = std::stoi(s.substr(6));
        if(x % y == 0 && x / y == 787) {
            std::cout << x << '\n';
            return 0;
        }
    } while(std::next_permutation(s.begin(), s.end()));
}