/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"
#include "C++/LazySegmentTree.hpp"

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
	VEC(ll,a,n);
	VEC(int,b,m);
	RUQRSM<ll,0> seg(a);
	each(el,b) {
		ll c=seg[el];
		seg.set(el,0);
        const ll q=c/n;
		c%=n;
        seg.update(0,n,q);
        if(++el+c<=n) {
            seg.update(el,el+c,1);
        } else {
            seg.update(el,n,1);
            seg.update(0,el+c-n,1);
        }
	}
	out(seg);
}