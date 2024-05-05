/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/ds/uf/UnionFind.hpp"
#include "C++/graph/WeightedGraph.hpp"
#include "C++/graph/mst/kruskal.hpp"
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
    INT(n,m);
    w_graph g(n);
    UnionFind uf(n);
    rep(m) {
        INT(k,c);
        VEC(int,a,k);
        rep(j,1,k-1) {
            g.add(a[0],a[j],c);
            uf.unite(a[0]-1,a[j]-1);
        }
    }
    if(uf.groups().size()!=1) {
        fin(-1);
    }
    out(kruskal(g.get_edge(), n).cost);
}