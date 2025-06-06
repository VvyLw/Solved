/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"

int main() {
    VvyLw::wa_haya_exe();
    now(start);
    int T = 1;
    // std::cin >> T;
    REP(T) {
        VvyLw::solve();
    }
    now(stop);
    time(start, stop);
}

// --------------------------------------------------------------------------------------------------------------

const std::vector<std::string> t1 = {"gray","brown","green","cyan","blue","yellow","orange","red"}, t2 = {"gray","green","blue","yellow","red"}, t3 = {"gray","green","cyan","blue","violet","orange","red"};

void VvyLw::solve() {
    man::vec::vs s(3);
    std::cin >> s;
    std::unordered_set<std::string> u1(t1.cbegin(), t1.cend()), u2(t2.cbegin(), t2.cend()), u3(t3.cbegin(), t3.cend());
    iter::sort(s);
    int cnt = 0;
    do {
        if(u1.contains(s[0]) && u2.contains(s[1]) && u3.contains(s[2])) {
            cnt++;
        }
    } while(iter::next_permutation(s).found);
    std::cout << man::yes(cnt == 1) << '\n';
}