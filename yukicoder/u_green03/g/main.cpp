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
#include <cassert>
#include <algorithm>
#include <unordered_set>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    char a;
    std::cin >> a;
    std::string s(2, a);
    std::unordered_set<std::string> t;
    while(true) {
        if(t.contains(s)) {
            std::cout << "! LOSE" << std::endl;
            std::exit(0);
        }
        std::cout << "? " << s << std::endl;
        t.emplace(s);
        if(std::ssize(t) == 51) {
            break;
        }
        char dummy;
        std::cin >> dummy >> s;
        assert(std::ssize(s) == 2);
        if(t.contains(s)) {
            break;
        }
        t.emplace(s);
        std::ranges::reverse(s);
    }
    std::cout << "! WIN" << std::endl;
}