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
	LL(n,m,k);
	if(n>m) {
		swap(n,m);
	}
	ll i=0;
	vi a,b;
	while(i<=30) {
		if(i%n==0&&i%m!=0) {
			a.emplace_back(i);
		}
		if(i%n!=0&&i%m==0) {
			b.emplace_back(i);
		}
		i++;
	}
	debug(a,b);//*/
	const ll g=gcd(n,m),l=lcm(n,m);
	if(g==n) {
		
	}
}