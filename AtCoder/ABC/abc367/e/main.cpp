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
	LL(n,k);
	VEC(int,x,n);
	--x;
	VEC(int,a,n);
	if(k==0) {
		fin(a);
	}
	const int z=ceil(log(k,2));
	wi dbl(z,vi(n));
	rep(n) {
		dbl.front()[i]=x[i];
	}
	rep(z-1) {
		rep(j,n) {
			dbl[i+1][j]=dbl[i][dbl[i][j]];
		}
	}
	auto id=iot(n);
	for(int i = 0; k > 0; ++i) {
		if(k&1) {
			rep(j,n) {
				id[j]=dbl[i][id[j]];
			}
		}
		k>>=1;
	}
	vi b(n);
	rep(n) {
		b[i]=a[id[i]];
	}
	out(b);
}