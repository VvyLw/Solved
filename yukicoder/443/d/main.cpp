#pragma GCC optimize("O2")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <valarray>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int64_t n, k;
    std::cin >> n >> k;
    const auto sol = [&k](const int64_t n) -> std::string {
        std::string s;
        if(--k == 0) {
            return "0";
        }
        std::valarray<int64_t> v(1, 20);
        int id = 0;
        for(int64_t i = n; i > 0; ++id, i /= 10) {
            v[id + 1] = v[id] * (i % 10 + 1);
        }
        bool c = false;
        dump(v);
        while(id >= 0) {
            const auto x = k / v[id];
            if(x > 0 || c) {
                s += std::to_string(x);
                c = true;
            }
            k %= v[id--];
        }
        return s;
    };
    std::cout << sol(n) << '\n';
}