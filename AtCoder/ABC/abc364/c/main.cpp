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
	LL(n,x,y);
	VEC(int,a,n);
	VEC(int,b,n);
	Sortt(a);
	Sortt(b);
	ll p=0,q=0;
	rep(i,n) {
		p+=a[i];
		q+=b[i];
		if(p>x || q>y) {
			fin(i+1);
		}
	}
	out(n);
}