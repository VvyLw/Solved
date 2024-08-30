#pragma GCC optimize("O2")
#ifdef local
#include <C++/core/io/debug_print.hpp>
#else
#define dump(...) void(0);
#endif

#include <iostream>
namespace man {

}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n;
    std::string s;
    std::cin >> n >> s;
    if(s.find("404") == std::string::npos) {
        std::cout << "Not";
    }
    std::cout << "Found\n";
}