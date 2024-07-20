#pragma GCC optimize("O3")
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
	INT(n,k);
	STR(s);
	Sort(s);
	int cnt=0;
	const auto is_pld=[](const string &s) -> bool { return s==revd(s); };
	do {
		bool ok=true;
		rep(n-k+1) {
			const string t=s.substr(i,k);
			dump(t);
			ok&=!is_pld(t);
		}
		if(ok) {
			cnt++;
		}
	} while(nxp(s));
	out(cnt);
}