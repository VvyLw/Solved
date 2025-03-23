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
	VEC(int,a,n);
	map<int, vi> m;
	rep(i, n) {
		m[a[i]].emplace_back(i + 1);
	}
	set<P<int, vi>> s;
	each(k, v, m) {
		if(ssize(v) == 1) {
			s.emplace(make_pair(k, v));
		}
	}
	out(s.empty() ? -1 : s.rbegin()->second.front());
}