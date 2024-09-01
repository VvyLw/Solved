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
    INT(n);
    VEC(int,h,n);
    ll t=0;
    rep(n) {
        dump(t,h[i]);
        while(t%3!=2 && h[i]>0) {
            t++;
            h[i]--;
        }
        dump(t,h[i]);
        if(h[i]>0) {
            h[i]-=3;
            t++;
        }
        dump(t,h[i]);
        if(h[i]<=0) {
            continue;
        }
        t+=(h[i]/5)*3;
        t+=min(h[i]%5,3);
    }
    out(t);
}