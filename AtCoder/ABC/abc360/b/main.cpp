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
	STR(s,t);
	const int n = s.size(), m = t.size() - 1;
	bool ok=false;
	rep(i,1,n-1) {
		rep(j,1,i) {
			if(m>(n-j)/i+1) {
				continue;
			}
			string u;
			rep(k,j-1,n-1,j) {
				u+=s[k];
			}
			ok|=u==t;
		}
	}
	Yes(ok);
}