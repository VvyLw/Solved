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
    VEC(int,a,n);
    vi b(n);
    rep(n) {
        const auto pf=prmfct(a[i]);
        each(e,pf) {
            b[i]+=e.second;
        }
    }
    dump(b);
    out(accumulate(all(b),0,[](const int acc, const int x){ return acc^x; })?"Anna":"Bruno");
}