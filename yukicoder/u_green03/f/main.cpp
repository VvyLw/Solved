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
#include <stack>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::views;
    std::string s;
    std::cin >> s;
    std::stack<char> sk;
    int st = 0;
    for(const auto &c: s) {
        if(c == '<') {
            st++;
        }
        if(!sk.empty() && c == '>') {
            if(st == 0 || sk.top() != '=') {
                sk.emplace(c);
                st = 0;
                continue;
            }
            while(st > 0 && sk.top() == '=') {
                sk.pop();
            }
            sk.pop();
            st--;
            continue;
        }
        sk.emplace(c);
    }
    std::cout << sk.size() << '\n';
}