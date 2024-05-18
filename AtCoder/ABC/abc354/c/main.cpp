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
	VEC(pi,c,n);
	auto d=c;
	map<pi,int> id;
	rep(n) {
		id[c[i]]=i;
	}
	stable_sort(all(c),[&](const pi &p, const pi &q){
		if(p.first==q.first) {
			return p.second<q.second;
		}
		return p.first>q.first;
	});
	stable_sort(all(d),[&](const pi &p, const pi &q){
		if(p.second==q.second) {
			return p.first>q.first;
		}
		return p.second<q.second;
	});
	dump(c,d);
	unordered_set<int> away;
	int min_cost=c.front().second, max_v=d.front().first;
	rep(i,1,n-1) {
		if(!chmin(min_cost,c[i].second)) {
			away.emplace(id[c[i]]);
		}
		if(!chmax(max_v,d[i].first)) {
			away.emplace(id[d[i]]);
		}
	}
	vi ans;
	rep(n) {
		if(!away.contains(i)) {
			ans.emplace_back(i+1);
		}
	}
	out(ans.size());
	out(ans);
}