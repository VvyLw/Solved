/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/graph.hpp"

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
	graph g(n);
	g.input(m);
	vb vis(n);
	int ans = 0;
	ll val = 0;
	vi memo;
	const auto dfs = [&](const auto &f, const int v = 0) -> void {
		vis[v] = true;
		each(ed, g[v]) {
			if(vis[v]) {
				continue;
			}
			if(a[ed.src] < a[ed.to]) {
				continue;
			}
			ans += a[ed.src] + a[ed.to];
			f(f, ed.to);
		}
	};
	dfs(dfs);
	out(ans);
}