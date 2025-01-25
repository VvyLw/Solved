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
	INT(n,x);
	VEC(tri,a,n);
	wi dp(n+1,vi(x+1,INF));
	rep(n) {
		rep(j,x+1) {
			if(j>=a[i][2]) {
				chmin(dp[i+1][j], dp[i][j-a[i][2]] + a[i][1]);
			}
		}
	}
	dump(dp);
}