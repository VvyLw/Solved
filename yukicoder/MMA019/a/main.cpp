#pragma GCC optimize("O2")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <cassert>
#include <cmath>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    assert(!(a == 0 && b == 0));
    if(a == 0) {
        std::cout << d / b << '\n';
    } else if(b == 0) {
        std::cout << c / a << '\n';
    } else {
        std::cout << std::min(c / a, d / b) << '\n';
    }
}