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
	STR(s);
	const int n=s.size();
	wi sum(n+1,vi(26));
	rep(n) {
		rep(j,26) {
			sum[i+1][j]=sum[i][j];
		}
		sum[i+1][s[i]-'A']++;
	}
	dump(sum);
	ll ret=0;
	rep(i,1,n-2) {
		rep(j,26) {
			ret+=sum[i][j]*(sum[n][j]-sum[i+1][j]);
		}
	}
	out(ret);
}