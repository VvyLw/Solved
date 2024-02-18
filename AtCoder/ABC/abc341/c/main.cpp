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
	INT(h,w,n);
	STR(t);
	VEC(string,s,h);
	int cnt=0;
	rep(h) {
		rep(j,w) {
			if(s[i][j]=='#') {
				continue;
			}
			int x=i,y=j;
			bool ok=true;
			rep(k,n) {
				const char c = t[k];
				if(c=='L') {
					y--;
				} elif(c=='R') {
					y++;
				} elif(c=='U') {
					x--;
				} else {
					x++;
				}
				if(!scope(0,x,h-1)||!scope(0,y,w-1)) {
					ok=false;
					break;
				}
				ok&=s[x][y]=='.';
			}
			if(ok) {
				debug(x,y);
				cnt++;
			}
		}
	}
	out(cnt);
}