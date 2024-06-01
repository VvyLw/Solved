/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/math/Modint.hpp"
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
	LL(n,m);
	dump(to_bin(m));
	mint res=0;
	rep(bitdigit(m)) {
		const ll k=1LL<<i,r=(n+1)%(2*k);
		ll cnt=(n+1)/(2*k)*k;
		cnt+=max(0LL,r-k);
		if(m&k) {
			res+=cnt;
		}
	}
	out(res);
}