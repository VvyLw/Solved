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
	INT(n, q);
	int x = 1, y = 0;
	const auto move = [&x, &y](const char c) -> void {
		if(c == 'R') {
			x++;
		} elif(c == 'L') {
			x--;
		} elif(c == 'U') {
			y++;
		} else {
			y--;
		}
	};
	deque<pi> parts(n);
	rep(n) {
		parts[i] = {i + 1, 0};
	}
	rep(q) {
		INT(t);
		if(t == 1) {
			CHR(c);
			move(c);
			parts.emplace_front(x, y);
			parts.pop_back();
		} else {
			INT(p);
			out(parts[--p]);
		}
	}
}