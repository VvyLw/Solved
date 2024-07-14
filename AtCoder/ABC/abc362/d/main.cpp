/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/graph/WeightedGraph.hpp"
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
	VEC(int,a,n);
	w_graph<false> g(2*n);
	rep(i,1,n) {
		g.add(i,n+i,a[i-1]);
	}
	rep(m) {
		INT(u,v,b);
		g.add(u,n+v,b);
		g.add(v,n+u,b);
	}
	auto sp=g.dijkstra(0).get();
	dump(sp);
	rtt(sp,n+1);
	sp.resize(n-1);
	out(sp);
}