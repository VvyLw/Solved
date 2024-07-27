#pragma GCC target("avx")
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
	INT(n,q);
	VEC(ll,a,n);
	Sort(a);
	while(q--) {
		INT(b,k);
		const int i=LB(a,b);
		if(i==0) {
			out(abs(a[k-1]-b));
		} elif(i==n-1) {
			out(abs(a[n-k]-b));
		} else {
			int d=1,e=0;
			rep(j,k) {
				int x=INF,y=INF;
				if(scope(0,i-d,n-1)) {
					x=abs(a[i-d]-b);
				}
				if(scope(0,i+e,n-1)) {
					y=abs(a[i+e]-b);
				}
				if(x==INF) {
					e++;
				} elif(y==INF) {
					d++;
				} else {
					if(x<=y) {
						d++;
					} else {
						e++;
					}
				}
				if(j==k-1) {
					dump(min(x,y));
					out(min(x,y));
				}
			}
		}
	}
}