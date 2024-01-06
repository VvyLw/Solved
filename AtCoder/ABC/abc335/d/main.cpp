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
	V<vs> a(n, vs(n));
	int u = 0, v = n - 1;
	pi p = {u+1, u}, q = {u, v}, r = {v, v}, s = {v, u};
	int x = 0, y = 0, z = 0, i = 1;
	while(i < sqr(n)) {
		a[x][y] = to_string(i);
		i++;
		if(z == 0) {
			y++;
		} elif(z == 1) {
			x++;
		} elif(z == 2) {
			y--;
		} else {
			x--;
		}
		const pi tmp = {x, y};
		if(tmp == q) {
			z=1;
		} elif(tmp == r) {
			z=2;
		} elif(tmp == s) {
			z=3;
		} elif(tmp == p) {
			z=0;
			u++,v--;
			p = {u + 1, u};
			q = {u, v};
			r = {v, v};
			s = {v, u};
		}
	}
	a[x][y] = "T";
	vout(a);
}