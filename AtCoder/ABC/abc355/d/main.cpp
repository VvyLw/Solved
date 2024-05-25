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
	VEC(pi,s,n);
	Sort(s);
	dump(s);
	pqr<int> t;
	ll ans=0;
	rep(n) {
		while(t.size() && t.top()<s[i].first) {
			t.pop();
		}
		ans+=ssize(t);
		t.emplace(s[i].second);
		dump(t);
	}
	out(ans);
}