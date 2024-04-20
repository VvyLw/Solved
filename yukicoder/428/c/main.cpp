/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/math/psum/psum.hpp"

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
    LL(n,m,w);
    VEC(ll,a,n);
    VEC(int,b,m);
    VEC(int,c,m);
    Sortt(a);
    psum p(a);
    const auto s=p.get();
    ll ans=0;
    rep(1<<m) {
        ll wg=0,val=0;
        rep(j,n) {
            bif(i,j) {
                wg+=b[j];
                val+=c[j];
            }
        }
        if(wg<=w) {
            val+=s[min(n,w-wg)];
            chmax(ans,val);
        }
    }
    out(ans);
}