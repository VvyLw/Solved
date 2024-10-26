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
#include "C++/graph/Graph.hpp"
}
int main() {
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    using namespace std::ranges;
    using namespace std::views;
    int n, m;
    std::cin >> n >> m;
    man::graph<false> g(n);
    g.input(m);
    
}