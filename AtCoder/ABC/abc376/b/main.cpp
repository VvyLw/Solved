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
	INT(n,q);
	int l=1,r=2,ret=0;
	while(q--) {
		P<char, int> p;
		in(p);
		if(p.first=='L') {
			const int x=abs(p.second-l),y=n-x;
			dump(p.first,x,y);
			if(x<=y) {
				ret+=x;
			} else {
				ret+=y;
			}
			l=p.second;
		} else {
			const int x=abs(p.second-r),y=n-x;
			dump(p.first,x,y);
			if(x<=y) {
				ret+=x;
			} else {
				ret+=y;
			}
			r=p.second;
		}
	}
	out(ret);
}