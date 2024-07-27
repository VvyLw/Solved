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
	INT(h,w,s,t);
	VEC(string,c,h);
	STR(x);
	const auto move=[&](const char d) -> void {
		if(d=='U') {
			if(scope(1,s-1,h)&&c[s-2][t-1]=='.') {
				s--;
			}
		} elif(d=='D') {
			if(scope(1,s+1,h)&&c[s][t-1]=='.') {
				s++;
			}
		} elif(d=='L') {
			if(scope(1,t-1,w)&&c[s-1][t-2]=='.') {
				t--;
			}
		} else {
			if(scope(1,t+1,w)&&c[s-1][t]=='.') {
				t++;
			}
		}
		dump(s,t);
	};
	each(y,x) {
		move(y);
	}
	out(s,t);
}