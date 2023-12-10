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
	INT(k,g,m);
	int grs=0, mg=0;
	rep(k) {
		if(grs==g) {
			grs=0;
		} elif(mg==0) {
			mg=m;
		} else {
			const int x = min(g-grs, mg);
			grs += x;
			if(grs>g) grs=g;
			mg -= x;
		}
	}
	out(grs,mg);
}