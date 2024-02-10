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
	LL(n);
	ll ans=0;
	map<ll,ll> m;
	m[n]++;
	while(m.lower_bound(2)!=m.end()) {
		const ll x=kymax(m);
		m[x/2]+=m[x];
		m[Ceil(x,2)]+=m[x];
		ans+=x*m[x];
		m.erase(x);
		debug(m);
	}
	out(ans);
}