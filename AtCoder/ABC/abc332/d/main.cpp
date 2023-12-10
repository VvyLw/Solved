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
	INT(h,w);
	WEC(int,a,h,w);
	WEC(int,b,h,w);
	map<int,int> m1,m2;
	rep(h) {
		rep(j,w) {
			m1[a[i][j]]++;
			m2[b[i][j]]++;
		}
	}
	if([&]{
		bool ok=true;
		each(ky,vl,m1) {
			ok&=vl==m2[ky];
		}
		return !ok;
	}()) {
		fin(-1);
	}
	const auto swap_sd=[&](const int x) {
		rep(h) {
			swap(a[i][x],a[i][x+1]);
		}
	};
	int cnt=0;
	vb vis(h,w);
	const auto dfs = [&](const auto &f, const int x, const int y) -> void {
		const int val=b[x][y];
		int p=0,q=0;
		rep(h) {
			rep(j,w) {
				if(a[i][j]==val) {
					p=i,q=j;
				}
			}
		}
		debug(p,q);
		rep(h) {
			rtt(a[i],y-q);
			cnt+=abs(y-q);
		}
		debug(a);
		f(f,x+1,y);
		f(f,x,y+1);
	};
	dfs(dfs,0,0);
	out(cnt);
}