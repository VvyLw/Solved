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
	INT(n,a,b);
	const int c = a + b;
	VEC(int,d,n);
	V<int> e = d - (d[0] - 1);
	const auto chk = [a](const V<int> v) -> bool {
		return All(v, [a](const int x){ return x <= a; });
	};
	d %= c;
	e %= c;
	dump(d, e);
	Yes(chk(d) || chk(e));
}