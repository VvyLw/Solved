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
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::ranges;
    using namespace std::views;
    std::string s, t;
    std::cin >> s >> t;
    assert(std::ssize(s) == 2 && std::ssize(t) == 2);
    int a = 0, b = 0, o = 0, ab = 0;
    for(const auto c: s) {
        for(const auto d: t) {
            if(c == 'A') {
                if(d == 'A' || d == 'O') {
                    a++;
                } else {
                    ab++;
                }
            } else if(c == 'B') {
                if(d == 'B' || d == 'O') {
                    b++;
                } else {
                    ab++;
                }
            } else {
                if(d == 'A') {
                    a++;
                } else if(d == 'B') {
                    b++;
                } else {
                    o++;
                }
            }
        }
    }
    const int pa = 25 * a, pb = 25 * b, po = 25 * o, pab = 25 * ab;
    std::cout << pa << ' ' << pb << ' ' << pab << ' ' << po << '\n';
}