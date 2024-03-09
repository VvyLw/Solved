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
    INT(m);
    VEC(int,b,m);
    INT(l);
    VEC(int,c,l);
    vi d;
    each(e,a) {
        each(f,b) {
            each(g,c) {
                d.emplace_back(e+f+g);
            }
        }
    }
    unq(d);
    INT(q);
    while(q--) {
        INT(x);
        Yes(BS(d,x));
    }
}