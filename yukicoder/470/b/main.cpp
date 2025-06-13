/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/math/Modint.hpp"

int main() {
    now(start);
    VvyLw::wa_haya_exe();
    now(stop);
    time(start, stop);
}

// --------------------------------------------------------------------------------------------------------------

man::Comb<mint> comb;

inline void VvyLw::solve() noexcept {
    std::string n;
    input(n);
    const int m = std::ssize(n);
    std::array<int, 10> cnt{};
    for(const auto &d: n) {
        cnt[d - '0']++;
    }
    mint ret = comb.fact(m), neg = comb.fact(m - 1);
    for(const auto i: iota(0, 10)) {
        ret /= comb.fact(cnt[i]);
        neg /= comb.fact(i == 0 ? cnt[i] - 1 : cnt[i]);
    }
    // iter::sort(n);
    // std::unordered_set<int> s;
    // do {
    //     const int x = man::to_ten(n);
    //     if(m == std::ssize(std::to_string(x))) {
    //         s.emplace(x);
    //     }
    // } while(iter::next_permutation(n).found);
    // dump(std::ssize(s), s);
    ret -= neg;
    println(ret);
}