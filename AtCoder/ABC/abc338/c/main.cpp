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
	VEC(int,q,n);
	VEC(int,a,n);
	VEC(int,b,n);
	const ll Q=vsum(q),A=vsum(a),B=vsum(b);
	const int da=Q/A,db=Q/B;
	ll ans=0,tmp=0,cost=0;
	rep(da+1) {
		cost+=A*i;
		tmp+=i;
		rep(j,db+1) {
			cost+=B*j;
			tmp+=j;
			if(cost<=Q) {
				chmax(ans,tmp);
			}
			cost-=B*j;
			tmp-=j;
		}
		cost-=A*i;
		tmp-=i;
	}
	out(ans);
}