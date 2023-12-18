/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/MST.hpp"

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
    V<edge> edges;
    rep(n-1) {
        INT(u,v,a,b);
        --u,--v;
        edges.emplace_back(u, v, a);
        edges.emplace_back(v, u, b);
    }
    vi ans(n);
    rep(n) {
        ans[i] = directed(edges, n, i).cost;
    }
    out(ans);
}