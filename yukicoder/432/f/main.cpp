#include <iostream>
#include <unordered_set>
int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::unordered_set<char> t;
    bool ok = false;
    for(const auto &c: s) {
        ok |= t.contains(c);
        t.emplace(c);
    }
    std::cout << (ok ? "Yes\n" : "No\n");
}