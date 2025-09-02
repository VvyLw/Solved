/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "C++/template.hpp"

int main() {
	now(start);
	VvyLw::wa_haya_exe();
	now(stop);
	time(start, stop);
}

// --------------------------------------------------------------------------------------------------------------


inline void VvyLw::solve() noexcept {
	int q;
	input(q);
	pqr<int> pq;
	REP(q) {
		int t;
		input(t);
		if(t == 1) {
			int x;
			input(x);
			pq.emplace(x);
		} else {
			println(pq.top());
			pq.pop();
		}
	}
}