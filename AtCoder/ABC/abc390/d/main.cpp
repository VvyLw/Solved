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
	VEC(ll,a,n);
	unordered_set<ll> s;
	rep(1<<n) {
		vi b=a;
		rep(j,n) {
			rep(k,n) {
				if(j>=k) {
					continue;
				}
				if(i>>j&1 && i>>k&1) {
					b[j]+=b[k];
					b[k]=0;
				}
			}
		}
		s.emplace(accumulate(all(b), 0LL, [](const ll a, const ll b){ return a^b; }));
	}
	out(s.size());
}