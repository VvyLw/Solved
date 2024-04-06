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
	VEC(string,a,h);
	pi s,t;
	rep(h) {
		rep(j,w) {
			if(a[i][j]=='S') {
				s={i,j};
			}
			if(a[i][j]=='T') {
				t={i,j};
			}
		}
	}
	wi med(h,vi(w)),eng(h,vi(w,-INF));
	INT(n);
	rep(n) {
		INT(r,c,e);
		med[--r][--c]=e;
	}
	queue<pi> q;
	q.emplace(s);
	while(q.size()) {
		const auto [f,g]=q.front();
		q.pop();
		if(med[f][g]) {
			if(chmax(eng[f][g],med[f][g])) {
				med[f][g]=0;
			}
		}
		if(eng[f][g]<=0) {
			continue;
		}
		rep(i,1,4) {
			const int x=f+dx[i],y=g+dy[i];
			if(!scope(0,x,h-1)||!scope(0,y,w-1)) {
				continue;
			}
			if(a[x][y]=='#') {
				continue;
			}
			chmax(eng[x][y],eng[f][g]-1);
			if(pi{x,y}==t&&eng[x][y]>=0) {
				fin("Yes");
			}
			q.emplace(x,y);
		}
	}
	dump(eng);
	Yes(eng[t.first][t.second]>=0);
}