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
	INT(n,m,k);
	vi c(m);
	wi a(m);
	vc r(m);
	rep(m) {
		in(c[i]);
		a[i].resize(c[i]);
		rep(j,c[i]) {
			in(a[i][j]);
		}
		in(r[i]);
	}
	dump(c,r,a);
	int cnt=0;
	rep(1<<n) {
		vi real(n);
		rep(j,n) {
			bif(i,j) {
				real[j]=true;
			}
		}
		int yes=0;
		rep(j,m) {
			int ok=0;
			rep(k,c[j]) {
				if(real[a[j][k]-1]) {
					ok++;
				}
			}
			if(ok>=k?r[j]=='o':r[j]=='x') {
				yes++;
			}
		}
		if(yes==m) {
			dump(real);
			cnt++;
		}
	}
	out(cnt);
}