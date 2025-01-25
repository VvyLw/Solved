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
	VEC(string,s,h);
	int xmax=-1, xmin=INF, ymax=-1, ymin=INF;
	rep(h) {
		rep(j,w) {
			if(s[i][j] == '#') {
				xmax=max(xmax,i);
				xmin=min(xmin,i);
				ymax=max(ymax,j);
				ymin=min(ymin,j);
			}
		}
	}
	dump(xmax,xmin,ymax,ymin);
	bool ok=true;
	rep(i,xmin,xmax) {
		rep(j,ymin,ymax) {
			ok &= s[i][j] != '.';
		}
	}
	Yes(ok);
}