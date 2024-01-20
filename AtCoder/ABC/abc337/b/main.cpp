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

string encode(const string& str) {
    int n = (int)str.size();
    string ret = ""; // 答えを格納
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back(str[l]);
        string num_str = to_string(r - l); // 出現回数
        ret += num_str;
        l = r;
    }
    return ret;
}

void VvyLw::solve() {
	STR(s);
	const auto t=encode(s);
	debug(t);
	string al;
	each(c,t) {
		if(isalpha(c)) {
			al+=c;
		}
	}
	debug(al);
	Yes(al==sorted(al));
}