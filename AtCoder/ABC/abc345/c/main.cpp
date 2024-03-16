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
    STR(s);
    vi cnt(26);
    each(c,s) {
        cnt[c-'a']++;
    }
    dump(cnt);
    ll res=0;
    rep(26) {
        rep(j,26) {
            if(i==j) {
                continue;
            }
            res+=cnt[i]*cnt[j];
        }
    }
    out(res==0?1:res/2);
}