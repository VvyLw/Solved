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
	INT(n);
	VEC(pi,p,n);
	rep(n) {
		int res=-1;
		ll dist=0;
		rep(j,n) {
			if(i==j) {
				continue;
			}
			if(chmax(dist,square(p[i]-p[j]))) {
				res=j+1;
			}
		}
		out(res);
	}
}