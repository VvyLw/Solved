#pragma GCC optimize("O2")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
namespace man {

}
const std::string s = "yuusaan", t = "uusaayuusaan";
/**
 * yuusaan
 * yuusaanuusaayuusaan
 * uusaayuusaan
 * yuusaanuusaayuusaan
 * yuusaanuusaayuusaanuusaayuusaanuusaayuusaan
 * yuusaanuusaayuusaanuusaayuusaanuusaayuusaanuusaayuusaanuusaayuusaan
 */
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int64_t n, k;
    std::cin >> n >> k;
    --k;
    if(n == 1) {
        std::cout << s[k] << '\n';
    } else {
        const int m = std::ssize(s);
        if(k < m) {
            std::cout << s[k] << '\n';
        } else {
            k -= m;
            std::cout << t[k % std::ssize(t)] << '\n';
        }
    }
}