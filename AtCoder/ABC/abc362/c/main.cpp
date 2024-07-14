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
	vi l(n),r(n);
	rep(n) {
		in(l[i],r[i]);
	}
	const bool ok=scope(vsum(l),0LL,vsum(r));
	Yes(ok);
	if(ok) {
		ll s=vsum(l);
		vi x=l;
		rep(n) {
			const ll d=min(r[i]-l[i],-s);
			s+=d;
			x[i]+=d;
		}
		out(x);
	}
}