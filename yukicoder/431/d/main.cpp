#include <iostream>
#include <ranges>
constexpr int INF = 1 << 30;
template <class T> constexpr inline bool chmin(T& a, const T& b) noexcept { if(a > b){ a = b; return true; } return false; }
template <class T> constexpr inline bool chmax(T& a, const T& b) noexcept { if(a < b){ a = b; return true; } return false; }
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n, cnt = 0;
    std::cin >> n;
    std::string s(n, 'a');
    for(const auto i: std::views::iota(0, n)) {
        int chk = INF;
        char c = '\0';
        for(const auto j: std::views::iota(0, 25)) {
            s[i] = 'a' + j;
            std::cout << "? " + s << std::endl;
            int now;
            std::cin >> now;
            if(chmax(cnt, now)) {
                c = 'a' + j;
            }
            chmin(chk, now);
        }
        if(chk == cnt) {
            c = 'z';
        }
        s[i] = c;
    }
    std::cout << "! " + s + "\n";
}