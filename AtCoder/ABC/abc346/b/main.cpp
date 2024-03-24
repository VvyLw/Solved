/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
using namespace std;
using namespace zia_qu;
using namespace Lady_sANDy;
using namespace Heileden;

int main() {
    VvyLw::wa_haya_exe();
    now(start);
    int T=1;
    //in(T);
    while(T--) VvyLw::solve();
    now(stop);
    time(start, stop);
}

// --------------------------------------------------------------------------------------------------------------


void VvyLw::solve() {
    INT(w,b);
    const string s = "wbwbwwbwbwbw";
    string t;
    rep(21) {
        t += s;
    }
    dump(t.size());
    const int n = t.size();
    bool ok = false;
    rep(n) {
        rep(j,i,n) {
            const auto u = t.substr(i, j);
            vi cnt(2);
            each(c, u) {
                cnt[c == 'b']++;
            }
            dump(u, cnt);
            ok |= cnt[0] == w && cnt[1] == b;
        }
    }
    Yes(ok);
}