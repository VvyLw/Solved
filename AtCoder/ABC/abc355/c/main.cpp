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
	INT(n,t);
	VEC(int,a,t);
	--a;
	vi cnt1(n), cnt2(n);
	unordered_set<int> dia1, dia2;
	rep(n) {
		dia1.emplace((n+1)*i);
		dia2.emplace(n-1+(n-1)*i);
	}
	dump(dia1,dia2);
	int ans = -1;
	rep(t) {
		if(dia1.contains(a[i])) {
			dia1.erase(a[i]);
		}
		if(dia2.contains(a[i])) {
			dia2.erase(a[i]);
		}
		if(dia1.empty() || dia2.empty()) {
			ans = i + 1;
			break;
		}
		const int x=a[i]/n,y=a[i]%n;
		dump(x,y);
		cnt1[x]++;
		cnt2[y]++;
		if(cnt1[x]==n || cnt2[y]==n) {
			ans=i+1;
			break;
		}
	}
	out(ans);
}