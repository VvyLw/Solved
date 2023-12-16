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
	INT(n);
	graph g(n);
	g.input(n-1);
	int ans=INF,cnt=INF;
	vb vis(n);
	const auto dfs = [&](const auto &f, const int v = 0) -> void {
		if(g[v].size() == 1 || vis[v]) {
			return;
		}
		vis[v] = true;
		rep(g[v].size()) {
			if(vis[g[v][i].to]) {
				if(i+1==g[v].size()) {
					chmin(ans,cnt);
					cnt=1;
				}
				continue;
			}
			debug(cnt);
			cnt++;
			f(f,g[v][i].to);
		}
	};
	dfs(dfs);
	chmin(ans,cnt);
	out(ans==INF?1:ans);
}