#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <ranges>
namespace man {

}
constexpr auto s = "IGNITION";
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::ranges;
    using namespace std::views;
    int i;
    std::cin >> i;
    std::cout << s[--i] << '\n';    
}