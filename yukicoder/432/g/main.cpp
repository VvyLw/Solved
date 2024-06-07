#include <iostream>
#include <vector>
#include <unordered_map>
template <class T, class U> inline bool chmax(T& a, const U& b){ if(a<b){ a=b; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& a, const U& b){ if(a>b){ a=b; return 1; } return 0; }
int main() {
    int n;
    std::cin >> n;
    std::unordered_map<int, std::vector<int>> m;
    for(int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        m[a].emplace_back(i);
    }
    int l = 0, r = n - 1;
    for(const auto &[k, v]: m) {
        const int x = std::ssize(v);
        if(x > 2) {
            std::cout << "0\n\n";
            return 0;
        } else if(x == 2) {
            chmax(l, v.front());
            chmin(r, v.back());
        }
    }
    if(l < r) {
        std::cout << r - l << '\n';
        for(int i = l; ++i <= r;) {
            std::cout << i << " \n"[i == r];
        }
    } else {
        std::cout << "0\n\n";
    }
}