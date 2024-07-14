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
	INT(x1,y1,x2,y2,x3,y3);
	vi a{x2-x1,y2-y1},b{x3-x1,y3-y1};
	bool ok=false;
	ok|=IP<ll>(a,b,0)==0;
	a={x1-x2,y1-y2};
	b={x3-x2,y3-y2};
	ok|=IP<ll>(a,b,0)==0;
	a={x1-x3,y1-y3};
	b={x2-x3,y2-y3};
	ok|=IP<ll>(a,b,0)==0;
	Yes(ok);
}