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
	n--;
	int m=1;
	ll s=0;
	while(true) {
		const ll x=9*pow<ll>(10,(m-1)/2);
		if(s+x>=n) {
			break;
		}
		s+=x;
		m++;
	}
	const ll r=n-s, st=pow<ll>(10,ceil(m,2)-1);
	const string t=to_string(st+r-1);
	out(t+revd(t).substr(m&1));
}