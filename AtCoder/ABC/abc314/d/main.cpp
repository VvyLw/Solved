#include <iostream>
#include <map>
int main() {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	int n, q, sw = 0;
	std::string s;
	std::cin >> n >> s >> q;
	std::map<int, char> mem;
	while(q--) {
		int t, x;
		char c;
		std::cin >> t >> x >> c;
		x--;
		if(t == 1) {
			s[x] = c;
			mem[x] = c;
		}
		else if(t == 2) {
			sw = -1;
			mem.clear();
		}
		else {
			sw = 1;
			mem.clear();
		}
	}
	if(sw == 1) {
		for(auto &c: s) {
			c = std::toupper(c);
		}
	}
	else if(sw == -1) {
		for(auto &c: s) {
			c = std::tolower(c);
		}
	}
	else mem.clear();
	for(const auto &[ky, vl]: mem) {
		s[ky] = vl;
	}
	std::cout << s << '\n';
}