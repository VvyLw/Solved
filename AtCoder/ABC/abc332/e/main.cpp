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
	INT(n,d);
	VEC(ll,w,n);
	pqr<ll> pq;
	rep(n) {
		pq.emplace(w[i]);
	}
	while(pq.size()>d) {
		const auto p = pq.top();
		pq.pop();
		const auto q = pq.top();
		pq.pop();
		pq.emplace(p+q);
	}
	vi x;
	while(pq.size()) {
		x.emplace_back(pq.top());
		pq.pop();
	}
	debug(x);
	fix(12);
	const ld ave=1.0L*vsum(x)/d;
	ld ans=0;
	rep(d) {
		ans+=sqr(x[i]-ave);
	}
	out(ans/d);
}