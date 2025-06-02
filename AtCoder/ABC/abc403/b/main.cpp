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
	STR(t,u);
	vi id;
	const int n=t.size();
	rep(n) {
		if(t[i]=='?') {
			id.emplace_back(i);
		}
	}
	assert(id.size()==4);
	for(char a='a'; a<='z'; ++a) {
		t[id[0]]=a;
		for(char b='a'; b<='z'; ++b) {
			t[id[1]]=b;
			for(char c='a'; c<='z'; ++c) {
				t[id[2]]=c;
				for(char d='a'; d<='z'; ++d) {
					t[id[3]]=d;
					if(rgxsr(t,u)) {
						return Yes();
					}
				}
			}
		}
	}
	No();
}