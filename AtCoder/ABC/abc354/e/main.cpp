#pragma GCC optimize("O3")
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
	VEC(pi,c,n);
	V<pi> pat;
	unordered_set<int> num;
	rep(n) {
		rep(j,i+1,n-1) {
			if(c[i].first==c[j].first||c[i].second==c[j].second) {
				pat.emplace_back(i,j);
				num.emplace(i);
				num.emplace(j);
			}
		}
	}
	dump(pat,num);
	bool tak=false;
	do {
		int turn=0;
		auto tmp=num;
		each(f,s,pat) {
			if(tmp.contains(f)&&tmp.contains(s)) {
				tmp.erase(f);
				tmp.erase(s);
				turn++;
			}
		}
		tak|=turn&1;
	} while(nxp(pat));
	out(tak?"Takahashi":"Aoki");
}