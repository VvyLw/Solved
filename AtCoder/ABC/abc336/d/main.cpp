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
	deque<int> d(n);
	rep(n) {
		d[i]=a[i];
	}
	int sz=0;
	while(n>1) {
		rep(i,n/2,n-1) {
			chmin(d[i],d[n-1-i]);
			debug(i,n-1-i);
		}
		debug(d);
	}
	out(sz);
}