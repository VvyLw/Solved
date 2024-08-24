/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/graph/Graph.hpp"
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
    INT(n,k);
    graph g(n);
    g.input(n-1);
    VEC(int,v,k);
    --v;
    vb vis(n);
    const auto dfs = [&](const auto &f, const int i) -> pi {
        vis[i]=true;
        int ret=1;
        bool jdg=BS(v,i);
        each(e,g[i]) {
            if(vis[e]) {
                continue;
            }
            const auto &[x,y]=f(f,e);
            if(y) {
                ret+=x;
                jdg=true;
            }
        }
        return jdg?pi{ret,1}:pi{0,0};
    };
    const auto ret=dfs(dfs,v.front());
    out(ret.first);
}