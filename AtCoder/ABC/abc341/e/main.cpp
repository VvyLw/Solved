#pragma GCC diagnostic ignored "-Wreorder"
#include <iostream>
#include <atcoder/lazysegtree>

template <class... Ts> constexpr auto symax(const Ts... a) noexcept { return std::max(std::initializer_list<std::common_type_t<Ts...>>{a...}); }
struct Data {
private:
	int len;
public:
	std::vector<int> mx, l, r;
	Data(): mx(2), l(2), r(2), len(0){}
	Data(const int x): mx(2), l(2), r(2), len(1) {
		for(int i = 0; i < 2; ++i) {
			mx[i] = l[i] = r[i] = i == x;
		}
	}
	Data flip() {
		Data res = *this;
		std::swap(res.mx[0], res.mx[1]);
		std::swap(res.l[0], res.l[1]);
		std::swap(res.r[0], res.r[1]);
		return res;
	}
	static Data merge(const Data &l, const Data &r) {
		Data res;
		for(int i = 0; i < 2; ++i) {
			res.l[i] = l.l[i] + (l.l[i] == l.len ? r.l[i] : 0);
			res.r[i] = r.r[i] + (r.r[i] == r.len ? l.r[i] : 0);
			res.mx[i] = symax(l.mx[i], r.mx[i], l.r[i] + r.l[i]);
		}
		res.len = l.len + r.len;
		return res;
	}
};

Data f(Data a, Data b) { return Data::merge(a, b); }
Data g(int a, Data b) { return a ? b.flip() : b; }
int h(int a, int b) { return a ^ b; }
Data ti() { return Data(); }
int ei() { return 0; }

int main() {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	int n, q;
	std::string s;
	std::cin >> n >> q >> s;
	std::vector<Data> a(n);
	for(int i = 0; i < n; ++i) {
		a[i] = Data(s[i] - '0');
	}
	atcoder::lazy_segtree<Data, f, ti, int, g, h, ei> seg(a);
	while(q--) {
		int t, l, r;
		std::cin >> t >> l >> r;
		l--;
		if(t == 1) {
			seg.apply(l, r, 1);
		} else {
			const auto res = seg.prod(l, r);
			std::cout << (*std::ranges::max_element(res.mx) <= 1 ? "Yes\n" : "No\n");
		}
	}
}