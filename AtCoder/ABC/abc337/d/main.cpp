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
	INT(h,w,k);
	VEC(string,s,h);
	int cnt=INF,tmp=0,cir=0;
	wb vis(h,vb(w));
	const auto dfs=[&](auto &f, const int i, const int j, const int d)->void {
		debug(1,i,j,d,cir,tmp);
		if(vis[i][j]) {
			return;
		}
		vis[i][j]=true;
		const int x=i+dx[d],y=j+dy[d];
		if(!scope(0,x,h-1)||!scope(0,y,w-1)) {
			chmin(cnt,tmp);
			return;
		}
		if(s[x][y]!='x') {
			if(s[x][y]=='.') {
				tmp++;
			}
			cir++;
			debug(2,x,y,cir,tmp);
			if(cir>=k) {
				chmin(cnt,tmp);
				return;
			}
			f(f,x,y,d);
		} else {
			debug(3,x,y,cir,tmp);
			if(cir>=k) {
				chmin(cnt,tmp);
			}
			return;
		}
	};
	rep(h) {
		rep(j,w) {
			if(s[i][j]=='o') {
				rep(d,4) {
					vis.assign(h,vb(w));
					tmp=cir=1;
					dfs(dfs,i,j,d);
				}
			}
		}
	}
	out(cnt==INF?-1:cnt);
}