#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
	INT(n,s,t);
	VEC(ti<4>,a,n);
	Sort(a);
	fix(15);
	ld ans=DINF;
	do {
		rep(1<<n) {
			ld ret=0;
			pi now={0,0};
			rep(j,n) {
				const pi p={a[j][0],a[j][1]},q={a[j][2],a[j][3]};
				const ld x=abs(now-p),y=abs(now-q),z=abs(p-q);
				dump(x,y,z);
				bif(i,j) {
					ret+=x/s+z/t;
					now=q;
				} else {
					ret+=y/s+z/t;
					now=p;
				}
			}
			dump(ret);
			chmin(ans,ret);
		}
	} while(nxp(a));
	out(ans);
}