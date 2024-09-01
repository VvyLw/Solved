/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/other/runlength.hpp"
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
	VEC(int,a,n);
	vi b;
	rep(n-1) {
		b.emplace_back(a[i+1]-a[i]);
	}
	const auto c=rle(b);
	ll ret=0;
	each(f,s,c) {
		ret+=s*(s+1L)/2;
	}
	out(ret+n);
}