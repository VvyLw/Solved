#pragma GCC optimize("O3")
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
    INT(n,h,w);
    VEC(pi,t,n);
    Sort(t);
    bool ok=false;
    do {
        rep(1<<n) {
            wb vis(h,vb(w));
            rep(j,n) {
                bif(i,j) {
                    const int x=t[j].first,y=t[j].second;
                    rep(a,h) {
                        bool z=false,f=false;
                        rep(b,w) {
                            if(a+x<=h&&b+y<=w) {
                                z=true;
                                rep(c,x) {
                                    rep(d,y) {
                                        z&=!vis[a+c][b+d];
                                    }
                                }
                            }
                            if(a+y<=h&&b+x<=w) {
                                f=true;
                                rep(c,y) {
                                    rep(d,x) {
                                        f&=!vis[a+c][b+d];
                                    }
                                }
                            }
                            if(z) {
                                rep(c,x) {
                                    rep(d,y) {
                                        vis[a+c][b+d]=true;
                                    }
                                }
                                break;
                            }
                            if(f) {
                                rep(c,y) {
                                    rep(d,x) {
                                        vis[a+c][b+d]=true;
                                    }
                                }
                                break;
                            }
                        }
                        if(z||f) {
                            break;
                        }
                    }
                }
            }
            bool tmp=true;
            rep(h) {
                tmp&=All(vis[i],[](const bool b){ return b; });
            }
            ok|=tmp;
        }
    } while(nxp(t));
    Yes(ok);
}