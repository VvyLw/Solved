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
	VEC(int,a,n);
	V<pi> p(n);
	int id=-1;
	rep(n) {
		p[i]={a[i],i};
		if(a[i]==-1) {
			id=i;
		}
	}
	vi ans;
	while(id!=n-1){
		ans.emplace_back(p[id].second);
		id=p[p[id].second].second;
	}
	out(ans);
}