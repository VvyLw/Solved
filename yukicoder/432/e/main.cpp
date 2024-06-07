#include <iostream>
#include <vector>
#include <ranges>
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cnt(n + 1);
    for(const auto i: std::views::iota(0, n)) {
        int a;
        std::cin >> a;
        cnt[a]++;
    }
    const int m = cnt.front();
    bool ok = false;
    for(const auto i: std::views::iota(1, n + 1)) {
        ok |= cnt[i] + m >= k;
    }
    std::cout << (ok ? "Yes\n" : "No\n");
}