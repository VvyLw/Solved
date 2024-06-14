#include <iostream>
#include <vector>
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<std::string> b(n);
    for(auto &e: a) {
        std::cin >> e;
    }
    for(auto &e: b) {
        std::cin >> e;
    }
    
}