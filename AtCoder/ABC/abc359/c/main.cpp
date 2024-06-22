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
	LL(sx,sy,tx,ty);
	if(mod(sx,2LL)!=mod(sy,2LL)) {
		sx--;
	}
	if(mod(tx,2LL)!=mod(ty,2LL)) {
		tx--;
	}
	ll ex=abs(sx-tx),ey=abs(sy-ty);
	dump(ex,ey);
	ex=max(0LL,ex-ey);
	out(ex/2+ey);
}