#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
#include <ranges>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    int n;
    std::cin >> n;
    if(n >= 2008) {
        std::cout << "Namiki Secondary School\n";
    } else if(n >= 1984) {
        std::cout << "Namiki High School\n";
    } else {
        std::cout << "None\n";
    }
}