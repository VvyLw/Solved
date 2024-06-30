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
	INT(n,t);
	STR(s);
	VEC(int,x,n);
	vi po, ne;
	rep(n) {
		if(s[i]=='1') {
			po.emplace_back(x[i]);
		} else {
			ne.emplace_back(x[i]);
		}
	}
	const int m1=po.size(),m2=ne.size();
	Sort(po);
	Sort(ne);
	dump(po,ne);
	dump(m1,m2);
	ll ans=0;
	for(int i=0,l=0,r=0; i<m1; ++i) {
		while(l<m2 && ne[l]<po[i]) {
			l++;
		}
		while(r<m2 && ne[r]<=po[i]+2*t) {
			r++;
		}
		ans+=r-l;
	}
	out(ans);
}