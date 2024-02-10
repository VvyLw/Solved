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
	VEC(tri,t,n-1);
	vi dp(n,LINF);
	dp[0]=0;
	for(int i=0,j=0; i<n&&j<n-1;i=t[i][2]-1,++j) {
		chmin(dp[i+1],dp[i]+t[i][0]);
		chmin(dp[j+1],dp[j]+t[j][0]);
		chmin(dp[t[i][2]-1],dp[i]+t[i][1]);
		chmin(dp[t[j][2]-1],dp[j]+t[j][1]);
	}
	debug(dp);
	out(dp[n-1]);
}