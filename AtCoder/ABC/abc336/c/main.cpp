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
	LL(n);
	if(n==1) {
		fin(0);
	}
	--n;
	const string s="02468";
	const auto res = revd(ten_to_adic(n,5));
	debug(res);
	string ans;
	each(el,res) {
		assert(scope<int>(0,el,4));
		ans+=s[el];
	}
	out(ans);
}