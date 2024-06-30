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
	VEC(int,w,n);
	wi b(n);
	ll sum=0;
	rep(n) {
		b[a[i]-1].emplace_back(w[i]);
		sum+=w[i];
	}
	dump(b);
	rep(n) {
		if(b[i].empty()) {
			continue;
		}
		sum -= Max(b[i]);
	}
	out(sum);
}