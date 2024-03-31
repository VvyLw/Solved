#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n), b;
    for(auto &el: a) {
        std::cin >> el;
    }
    b = a;
    std::ranges::sort(b);
    while(q--) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        std::cout << std::max(0L, std::ranges::lower_bound(b, a[x]) - std::ranges::upper_bound(b, a[y])) << '\n';
    }
}