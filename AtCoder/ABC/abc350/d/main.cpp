/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/ds/uf/UnionFind.hpp"
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
	INT(n,m);
	UnionFind uf(n);
	unordered_set<int> s;
	int res = 0;
	rep(m) {
		INT(a,b);
		a--,b--;
		const int x=uf.size(a),y=uf.size(b);
		res+=(x-1)*y;
		res+=x*(y-1);
		uf.unite(a,b);
	}
	out(res);
}