/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")//*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wdeprecated-copy"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
namespace VvyLw {
inline void wa_haya_exe() noexcept { cin.tie(nullptr); ios::sync_with_stdio(false); }
void solve();
} // VvyLw
mt19937 EhaL(hash<string>()("Huitloxopetl"));
mt19937 Random() {
    random_device seed_gen;
    mt19937 engine {seed_gen()};
    return engine;
}
using Timer = chrono::system_clock::time_point;
[[maybe_unused]] Timer start, stop;
#if local
void now(Timer &t){ t = chrono::system_clock::now(); }
void time(const Timer &t1, const Timer &t2){ cerr << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << "ms\n"; }
#else
[[maybe_unused]] void now(Timer &t){ void(0); }
[[maybe_unused]] void time(const Timer &t1, const Timer &t2){ void(0); }
#endif

// --------------------------------------------------------------------------------------------------------------

#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0; i<(n); ++i)
#define rep2(i,n) for(ll i=0; i<(n); ++i)
#define rep3(i,a,b) for(ll i=(a); i<=(b); ++i)
#define rep4(i,a,b,c) for(ll i=(a); i<=(b); i+=(c))
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rvp1(n) for(ll i=(n)-1; i>=0; i--)
#define rvp2(i,n) for(ll i=(n)-1; i>=0; i--)
#define rvp3(i,a,b) for(ll i=(a); i>=(b); i--)
#define rvp4(i,a,b,c) for(ll i=(a); i>=(b); i-=(c))
#define rvp(...) overload4(__VA_ARGS__,rvp4,rvp3,rvp2,rvp1)(__VA_ARGS__)
#define all1(v) v.begin(),v.end()
#define all2(v,a) v.begin(),v.begin()+a
#define all3(v,a,b) v.begin()+a,v.begin()+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)
#define rall1(v) v.rbegin(),v.rend()
#define rall2(v,a) v.rbegin(),v.rbegin()+a
#define rall3(v,a,b) v.rbegin()+a,v.rbegin()+b
#define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)
#define each1(elem,v) for(auto &elem: v)
#define each2(x,y,v) for(auto &[x,y]: v)
#define each3(x,y,z,v) for(auto &[x,y,z]: v)
#define each(...) overload4(__VA_ARGS__,each3,each2,each1)(__VA_ARGS__)
#define sqrp1(n) for(ll i=0; i*i<(n); ++i)
#define sqrp2(i,n) for(ll i=0; i*i<(n); ++i)
#define sqrp3(i,a,b) for(ll i=(a); i*i<=(b); ++i)
#define sqrp(...) overload3(__VA_ARGS__,sqrp3,sqrp2,sqrp1)(__VA_ARGS__)

using ll = long long;
using ld = long double;
using uint = unsigned;
using ul = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
template <class T> using L = numeric_limits<T>;
constexpr int dx[]={0,0,0,-1,1,-1,-1,1,1};
constexpr int dy[]={0,-1,1,0,0,-1,1,-1,1};
constexpr int MOD = 998244353;
constexpr int M0D = 1000000007;
constexpr int INF = 1 << 30;
constexpr ll LINF = (1LL << 61) - 1;
constexpr ld DINF = L<ld>::infinity();
template <class T> constexpr T LIM = L<T>::max();
#if __cplusplus >= 202100L
constexpr ld PI = numbers::pi;
constexpr ld E = numbers::e;
#else
const ld PI = acos(-1);
const ld E = 2.718281828459045;
#endif
namespace vectors {
template <class T> using V = vector<T>;
using vi = V<ll>;
using vu = V<ul>;
using vd = V<ld>;
using vc = V<char>;
using vs = V<string>;
using vb = V<bool>;
using wi = V<vi>;
using wu = V<vu>;
using wd = V<vd>;
using wc = V<vc>;
using ws = V<vs>;
using wb = V<vb>;
template <class T, class U> inline V<U> ndiv(T&& n, U&& v) noexcept {
    return V<U>(forward<T>(n), forward<U>(v));
}
template <class T, class... Ts> inline decltype(auto) ndiv(T&& n, Ts&&... v) noexcept {
    return V<decltype(ndiv(forward<Ts>(v)...))>(forward<T>(n), ndiv(forward<Ts>(v)...));
}
template <class T> constexpr V<T>& operator++(V<T>& v) noexcept { each(el,v) el++; return v; }
template <class T> constexpr V<T>& operator--(V<T>& v) noexcept { each(el,v) el--; return v; }
template <class T, class U> constexpr V<T>& operator+=(V<T>& v, const U x) noexcept { each(el,v) el+=x; return v; }
template <class T, class U> constexpr V<T>& operator-=(V<T>& v, const U x) noexcept { each(el,v) el-=x; return v; }
template <class T, class U> constexpr V<T>& operator*=(V<T>& v, const U x) noexcept { each(el,v) el*=x; return v; }
template <class T, class U> constexpr V<T>& operator/=(V<T>& v, const U x) noexcept { each(el,v) el/=x; return v; }
template <class T, class U> constexpr V<T>& operator%=(V<T>& v, const U x) noexcept { each(el,v) el%=x; return v; }
template <class T, class U> constexpr V<T> operator+(const V<T>& v, const U x) noexcept { V<T> res = v; res+=x; return res; }
template <class T, class U> constexpr V<T> operator-(const V<T>& v, const U x) noexcept { V<T> res = v; res-=x; return res; }
template <class T, class U> constexpr V<T> operator*(const V<T>& v, const U x) noexcept { V<T> res = v; res*=x; return res; }
template <class T, class U> constexpr V<T> operator/(const V<T>& v, const U x) noexcept { V<T> res = v; res/=x; return res; }
template <class T, class U> constexpr V<T> operator%(const V<T>& v, const U x) noexcept { V<T> res = v; res%=x; return res; }
} // vectors
using namespace vectors;
namespace pairs {
template <class T, class U> using P = pair<T, U>;
template <class T> using PP = P<T,T>;
using pi = PP<ll>;
using pd = PP<ld>;
using pc = PP<char>;
using ps = PP<string>;
template <class T> constexpr PP<T> operator+(const PP<T>& a, const PP<T>& b) noexcept { return {a.first + b.first, a.second + b.second}; }
template <class T> constexpr PP<T> operator-(const PP<T>& a, const PP<T>& b) noexcept { return {a.first - b.first, a.second - b.second}; }
template <class T> constexpr PP<T> operator-(const PP<T>& a) noexcept { return {-a.first, -a.second}; }
template <class T, class U> constexpr PP<T> operator*(const PP<T>& a, const U& b) noexcept { return {a.first * b, a.second * b}; }
template <class T, class U> constexpr PP<T> operator/(const PP<T>& a, const U& b) noexcept { return {a.first / b, a.second / b}; }
template <class T> constexpr PP<T>& operator+=(PP<T>& a, const PP<T>& b) noexcept { return a = a + b; }
template <class T> constexpr PP<T>& operator-=(PP<T>& a, const PP<T>& b) noexcept { return a = a - b; }
template <class T, class U> constexpr PP<T>& operator*=(PP<T>& a, const U& b) noexcept { return a = a * b; }
template <class T, class U> constexpr PP<T>& operator/=(PP<T>& a, const U& b) noexcept { return a = a / b; }
template <class T> constexpr bool operator==(const PP<T> &p, const PP<T> &q) noexcept { return p.first==q.first && p.second==q.second; }
template <class T> constexpr bool operator!=(const PP<T> &p, const PP<T> &q) noexcept { return !(p==q); }
template <class T> constexpr bool operator<(const PP<T> &p, const PP<T> &q) noexcept { if(p.first==q.first) return p.second<q.second; return p.first<q.first; }
template <class T> constexpr bool operator<=(const PP<T> &p, const PP<T> &q) noexcept { if(p.first==q.first) return p.second<=q.second; return p.first<q.first; }
template <class T> constexpr bool operator>(const PP<T> &p, const PP<T> &q) noexcept { if(p.first==q.first) return p.second>q.second; return p.first>q.first; }
template <class T> constexpr bool operator>=(const PP<T> &p, const PP<T> &q) noexcept { if(p.first==q.first) return p.second>=q.second; return p.first>q.first; }
template <class T, class U> constexpr bool operator==(const P<T,U> &p, const P<T,U> &q) noexcept { return p.first==q.first && p.second==q.second; }
template <class T, class U> constexpr bool operator!=(const P<T,U> &p, const P<T,U> &q) noexcept { return !(p==q); }
template <class T, class U> constexpr bool operator<(const P<T,U> &p, const P<T,U> &q) noexcept { if(p.first==q.first) return p.second<q.second; return p.first<q.first; }
template <class T, class U> constexpr bool operator<=(const P<T,U> &p, const P<T,U> &q) noexcept { if(p.first==q.first) return p.second<=q.second; return p.first<q.first; }
template <class T, class U> constexpr bool operator>(const P<T,U> &p, const P<T,U> &q) noexcept { if(p.first==q.first) return p.second>q.second; return p.first>q.first; }
template <class T, class U> constexpr bool operator>=(const P<T,U> &p, const P<T,U> &q) noexcept { if(p.first==q.first) return p.second>=q.second; return p.first>q.first; }
template <class T> inline PP<T> rotate(const PP<T>& a){ return {-a.second, a.first}; } // 90 degree ccw
template <class T> inline pd rotate(const PP<T>& a, const int ang) {
    assert(0<=ang && ang<360);
    const ld rad=PI*ang/180;
    return {a.first*cosl(rad)-a.second*sinl(rad), a.first*sinl(rad)+a.second*cosl(rad)};
}
template <class T> inline T dot(const PP<T>& a, const PP<T>& b){ return a.first * b.first + a.second * b.second; }
template <class T> inline T cross(const PP<T>& a, const PP<T>& b){ return dot(rotate(a), b); }
template <class T> inline T square(const PP<T>& a){ return dot(a, a); }
template <class T> inline ld grad(const PP<T>& a){ assert(a.first); return 1.0L * a.second / a.first; }
template <class T> inline ld abs(const PP<T>& a){ return hypotl(a.first, a.second); }
template <class T> inline T lcm(const PP<T>& a){ return std::lcm(a.first, a.second); }
template <class T> inline T gcd(const PP<T>& a){ return std::gcd(a.first, a.second); }
template <class T> inline PP<T> extgcd(const PP<T> &p) {
    T x=1,y=0,t1=0,t2=0,t3=1,a,b;
    tie(a,b)=p;
    while(b) {
        t1=a/b,a-=t1*b;
        swap(a,b);
        x-=t1*t2;
        swap(x,t2);
        y-=t1*t3;
        swap(y,t3);
    }
    return {x,y};
}
template <class T> inline PP<T> normalize(PP<T> a) {
    if(a == PP<T>{}) return a;
    a /= gcd(a);
    if(a < PP<T>{}) a = -a;
    return a;
}
template <class T, class U> inline P<U,T> swap(const P<T,U> &p){ P<U,T> ret={p.second,p.first}; return ret; }
template <class T, class U> inline V<P<U,T>> swap(const V<P<T,U>> &vp) {
    V<P<U,T>> ret;
    each(el,vp) ret.emplace_back(swap(el));
    return ret;
}
template <class T, class U> inline V<T> first(const V<P<T,U>> &vp) {
    V<T> res;
    each(el,vp) res.emplace_back(el.first);
    return res;
}
template <class T, class U> inline V<U> second(const V<P<T,U>> &vp) {
    V<U> res;
    each(el,vp) res.emplace_back(el.second);
    return res;
}
} // pairs
using namespace pairs;
template <size_t N> using ti = array<ll, N>;
using tri = ti<3>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqr = priority_queue<T,V<T>,greater<T>>;
template <class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using TREE = tree<T,null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <class T, class U> bool chmax(T& a, const U& b){ if(a<b){ a=b; return 1; } return 0; }
template <class T, class U> bool chmin(T& a, const U& b){ if(a>b){ a=b; return 1; } return 0; }
template <class T, class U> inline bool overflow_if_add(const T a, const U b){ return (LIM<T>-a)<b; }
template <class T, class U> inline bool overflow_if_mul(const T a, const U b){ return (LIM<T>/a)<b; }

namespace IO {
ostream &operator<<(ostream &dest, i128 value) {
    ostream::sentry s(dest);
    if(s) {
        u128 tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while(tmp);
        if(value < 0) {
            --d;
            *d = '-';
        }
        const int len = end(buffer) - d;
        if(dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(ios_base::badbit);
        }
    }
    return dest;
}
template <class T, class U> istream& operator>>(istream &is, P<T, U> &p){ is >> p.first >> p.second; return is; }
template <class T, size_t N> istream& operator>>(istream &is, array<T, N> &a){ each(el,a) is >> el; return is; }
template <class T> istream& operator>>(istream &is, V<T> &v){ each(el,v) is >> el; return is; }
template <class T> istream& operator>>(istream &is, deque<T> &dq){ each(el,dq) is >> el; return is; }
template <class T> inline bool in(T& x){ cin >> x; return 1; }
template <class Head, class... Tail> inline bool in(Head& head, Tail&... tail){ in(head); in(tail...); return 1; }
template <class T, class U> ostream& operator<<(ostream &os, const P<T, U> &p){ os << p.first << ' ' << p.second; return os; }
template <class T, size_t N> ostream& operator<<(ostream &os, const array<T, N> &a){ if(a.size()){ os << a.front(); for(auto i=a.begin(); ++i!=a.end();){ os << ' ' << *i; } } return os; }
template <class T> ostream& operator<<(ostream &os, const V<T> &v){ if(v.size()){ os << v.front(); for(auto i=v.begin(); ++i!=v.end();){ os << (' ') << *i; } } return os; }
template <class K, class V> ostream& operator<<(ostream &os, const map<K, V> &m){ if(m.size()){ os << m.begin()->first << ' ' << m.begin()->second; for(auto i=m.begin(); ++i!=m.end();){ os << '\n' << i->first << ' ' << i->second; } } return os; }
template <class T> ostream& operator<<(ostream &os, const set<T> &st){ if(st.size()){ os << *st.begin(); for(auto i=st.begin(); ++i!=st.end();){ os << ' ' << *i; } } return os; }
template <class T> ostream& operator<<(ostream &os, const multiset<T> &ms){ if(ms.size()){ os << *ms.begin(); for(auto i=ms.begin(); ++i!=ms.end();){ os << ' ' << *i; } } return os; }
template <class T> ostream& operator<<(ostream &os, const deque<T> &dq){ if(dq.size()){ os << dq.front(); for(auto i=dq.begin(); ++i!=dq.end();){ os << ' ' << *i; } } return os; }
void out(){ cout << '\n'; }
template <bool flush=false, class T> inline void out(const T& x){ cout << x << '\n'; if(flush) cout.flush(); }
template <bool flush=false, class Head, class... Tail> inline void out(const Head& head, const Tail&... tail){ cout << head << ' '; out<flush>(tail...); }
template <bool flush=false, class T> inline void vout(const T& v){ cout << v << '\n'; if(flush) cout.flush(); }
template <bool flush=false, class T> inline void vout(const V<T>& v){ rep(v.size()) cout << v[i] << '\n'; if(flush) cout.flush(); }
template <bool flush=false, class Head, class... Tail> inline void vout(const Head& head, const Tail&... tail){ cout << head << '\n'; vout<flush>(tail...); }
void fix(const short x){ cout << fixed << setprecision(x); }
void alpha(){ cout << boolalpha; }
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define UL(...) ul __VA_ARGS__; in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define VEC(type,name,size) V<type> name(size); in(name)
#define WEC(type,name,h,w) V<V<type>> name(h,V<type>(w)); in(name)
#define fin(...) do{ out(__VA_ARGS__); return; }while(false)
} // IO
using namespace IO;

namespace zia_qu {
#ifdef local
#include "../debug_print.hpp"
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) static_cast<void>(0)
#endif
#define elif else if
#define eid(el,v) &el-&v[0]
#define bif(bit,tar) if(((bit)>>(tar))&1)
#define nxp(x) next_permutation(all(x))
#define prp(x) prev_permutation(all(x))
#define strpl(s,a,b) regex_replace(s,regex(a),b)
#define rgxsr(s,rgx) regex_search(s,regex(rgx))
inline void YES(bool ok=1){ out(ok?"YES":"NO"); }
inline void NO(bool ok=1){ YES(!ok); }
inline void Yes(bool ok=1){ out(ok?"Yes":"No"); }
inline void No(bool ok=1){ Yes(!ok); }
inline void yes(bool ok=1){ out(ok?"yes":"no"); }
inline void no(bool ok=1){ yes(!ok); }
template <class T> inline T sqr(const T x){ return x*x; }
template <class T> inline T cub(const T x){ return x*x*x; }
template <class T> inline T Mod(const T x, const T m){ return (x+m)%m; }
template <class T> inline T Pow(T a, T b, const T mod=0) {
    T res=1;
    if(mod) {
        res%=mod;
        a%=mod;
    }
    while(b>0) {
        if(b&1) res*=a;
        if(mod) res%=mod;
        a*=a;
        if(mod) a%=mod;
        b>>=1;
    }
    return res;
}
inline ll Ceil(const ld x, const ll m){ return ceil(x/m); }
inline ld Round(const ld x, const ll m, const uint fx=0){ if(!fx) return round(x/m); const ul y=Pow<ul>(10,fx); return round((x*y)/m)/y; }
inline ld Log(const ll x, const ld base=2){ return log2(x)/log2(base); }
inline int bitdigit(const ll x){ return 64-__builtin_clzll(x); }
inline int popcnt(const ll x){ return __builtin_popcountll(x); }
inline int fione(const ll x){ return __builtin_ffsll(x); }
inline int zrcnt(const ll x){ return __builtin_ctzll(x); }
template <class T=ll> inline bool scope(const T a, const T x, const T b){ return a <= x && x <= b; }
inline bool isupper(const char c){ return std::isupper(c); }
inline bool isupper(const string &s){ bool ok=1; each(el,s) ok&=isupper(el); return ok; }
inline bool islower(const char c){ return std::islower(c); }
inline bool islower(const string &s){ bool ok=1; each(el,s) ok&=islower(el); return ok; }
inline bool isalpha(const char c){ return std::isalpha(c); }
inline bool isalpha(const string &s){ bool ok=1; each(el,s) ok&=isalpha(el); return ok; }
inline bool isdigit(const char c){ return std::isdigit(c); }
inline bool isdigit(const string &s){ bool ok=1, neg=s.front()=='-'; each(el,s){ if(neg){ neg=0; continue; } ok&=isdigit(el); } return ok; }
inline bool isalnum(const char c){ return std::isalnum(c); }
inline bool isalnum(const string &s){ bool ok=1; each(el,s) ok&=isalnum(el); return ok; }
inline bool isspace(const char c){ return std::isspace(c); }
inline bool isspace(const string &s){ bool ok=1; each(el,s) ok&=isspace(el); return ok; }
inline bool ispunct(const char c){ return std::ispunct(c); }
inline bool ispunct(const string &s){ bool ok=1; each(el,s) ok&=ispunct(el); return ok; }
inline bool isprint(const char c){ return std::isprint(c); }
inline bool isprint(const string &s){ bool ok=1; each(el,s) ok&=isprint(el); return ok; }
inline ll strins(string &s, const ll id, const string &t){ s.insert(id,t); return s.size(); }
inline string toupper(string s){ each(c,s) c=std::toupper(c); return s; }
inline string tolower(string s){ each(c,s) c=std::tolower(c); return s; }
inline vi ten_to_adic(ll n, const short base) {
    vi res;
    while(n) {
        res.emplace_back(n%base);
        n/=base;
    }
    return res;
}
inline ll adic_to_ten(const vi &v, const short base) {
    ll res=0;
    each(el,v) {
        res+=Pow<ll>(base,eid(el,v))*el;
    }
    return res;
}
inline string to_hex(const ll x) {
    stringstream ss;
    ss<<hex<<x;
    string s=ss.str();
    return s;
}
inline string to_oct(const ll x) {
    stringstream s;
    s<<oct<<x;
    return s.str();
}
inline string to_bin(const ll x) {
    stringstream ss;
    ss<<bitset<64>(x);
    string s=ss.str();
    reverse(all(s));
    s.resize(ten_to_adic(x,2).size());
    reverse(all(s));
    return s;
}
inline ll to_ten(const string &s, const short base){ return stoll(s,nullptr,base); }
inline i128 stoL(const string &s) {
    assert(isdigit(s));
    bool neg=s.front() == '-';
    i128 ret = 0;
    each(el,s) {
        if(neg) {
            neg = 0;
            continue;
        }
        ret = 10 * ret + el - '0';
    }
    if(s.front() == '-') ret = -ret;
    return ret;
}
template <class... Ts> constexpr ul sygcd(const Ts... a) noexcept { vector v=initializer_list<common_type_t<Ts...>>{a...}; ul g=0; each(el,v) g=gcd(g,el); return g; }
template <class... Ts> constexpr ul sylcm(const Ts... a) noexcept { vector v=initializer_list<common_type_t<Ts...>>{a...}; ul l=1; each(el,v) l=lcm(l,el); return l; }
template <class... Ts> constexpr auto symin(const Ts... a) noexcept { return min(initializer_list<common_type_t<Ts...>>{a...}); }
template <class... Ts> constexpr auto symax(const Ts... a) noexcept { return max(initializer_list<common_type_t<Ts...>>{a...}); }
template <class K, class U> inline V<K> kyl(const map<K,U> &m, const U val) {
    V<K> keys;
    for(auto it=m.cbegin(); it!=m.cend(); ++it) {
        if(it->second==val) keys.emplace_back(it->first);
    }
    return keys;
}
template <class K, class V> inline K kymin(const map<K,V> &m){ return m.begin()->first; }
template <class K, class V> inline K kymax(const map<K,V> &m){ return m.rbegin()->first; }
template <class K, class V> inline V kymin_v(const map<K,V> &m){ return m.begin()->second; }
template <class K, class V> inline V kymax_v(const map<K,V> &m){ return m.rbegin()->second; }
template <class K, class V> inline V vlmin(const map<K,V> &m){
    const auto pr = *min_element(all(m),[](P<K,V> const &x, P<K,V> const &y){ return x.second < y.second; });
    return pr.second;
}
template <class K, class V> inline V vlmax(const map<K,V> &m){
    const auto pr = *max_element(all(m),[](P<K,V> const &x, P<K,V> const &y){ return x.second < y.second; });
    return pr.second;
}
template <class K, class V> inline K vlmin_k(const map<K,V> &m){
    const auto pr = *min_element(all(m),[](P<K,V> const &x, P<K,V> const &y){ return x.second < y.second; });
    return pr.first;
}
template <class K, class V> inline K vlmax_k(const map<K,V> &m){
    const auto pr = *max_element(all(m),[](P<K,V> const &x, P<K,V> const &y){ return x.second < y.second; });
    return pr.first;
}
} // zia qu

namespace Lady_sANDy {
template <class T> inline void rev(T& v){ reverse(all(v)); }
template <class T> inline void rev(T& v, const int a, const int b){ reverse(all(v,a,b+1)); }
template <class T> inline T revd(const T& v){ auto c=v; rev(c); return c; }
template <class T> inline T revd(const T& v, const int a, const int b){ auto c=v; rev(c,a,b); return c; }
template <class T> inline void Sort(T& v){ sort(all(v)); }
template <class T> inline void Sort(T& v, const int a, const int b){ sort(all(v,a,b+1)); }
template <class T> inline T sorted(const T& v){ auto c=v; Sort(c); return c; }
template <class T> inline T sorted(const T& v, const int a, const int b){ auto c=v; Sort(c,a,b); return c; }
template <class T> inline void Sortt(T& v){ sort(rall(v)); }
template <class T> inline void Sortt(T& v, const int a, const int b){ sort(rall(v,v.size()-b-1,v.size()-a)); }
template <class T> inline T Sorted(const T& v){ auto c=v; Sortt(c); return c; }
template <class T> inline T Sorted(const T& v, const int a, const int b){ auto c=v; Sortt(c,a,b); return c; }
template <class T> inline void Sorth(T& v){ make_heap(all(v)); sort_heap(all(v)); }
template <class T> inline T mrg(const T& a, const T& b){ T res; merge(all(a),all(b),back_inserter(res)); return res; }
template <class T> inline T Min(const V<T>& v){ return *min_element(all(v)); }
template <class T> inline T Min(const V<T>& v, const int a, const int b){ return *min_element(all(v,a,b+1)); }
template <class T> inline T Max(const V<T>& v){ return *max_element(all(v)); }
template <class T> inline T Max(const V<T>& v, const int a, const int b){ return *max_element(all(v,a,b+1)); }
template <class T> inline int Min_i(const T& v){ return min_element(all(v))-v.begin(); }
template <class T> inline int Max_i(const T& v){ return max_element(all(v))-v.begin(); }
template <class T, class U> inline int LB(const T& v, const U x){ return lower_bound(all(v),x)-v.begin(); }
template <class T, class U> inline int UB(const T& v, const U x){ return upper_bound(all(v),x)-v.begin(); }
template <class T, class U> inline bool BS(const T& v, const U x){ return binary_search(all(v),x); }
template <class T, class U, class Boolean=bool> inline bool BS(const T& v, const U x, const Boolean &fn){ return binary_search(all(v),x,fn); }
template <class T, class Boolean=bool> inline bool All(const T& v, const Boolean &fn){ return all_of(all(v),fn); }
template <class T, class Boolean=bool> inline bool Exist(const T& v, const Boolean &fn){ return any_of(all(v),fn); }
template <class T, class Boolean=bool> inline int pt(T& v, const Boolean &fn){ auto p=partition(all(v),fn); return p-v.begin(); }
template <class T, class Boolean=bool> inline int ptp(const T& v, const Boolean &fn){ return partition_point(all(v),fn)-v.begin(); }
template <class T, class U> inline int fnd(const T& v, const U x){ auto itr=find(all(v),x); return itr!=v.end()?itr-v.begin():-1; }
template <class T> inline int src(const T& s, const T& t){ auto itr=search(all(s),all(t)); return itr!=s.end()?itr-s.begin():-1; }
template <class T, class U> inline void rpl(T& v, const U fn, const U r){ replace(all(v),fn,r); }
template <class T, class U, class Boolean=bool> inline void rplif(T& v, const Boolean &fn, const U r){ replace_if(all(v),fn,r); }
template <class T, class Boolean=bool> inline ul cntif(const T& v, const Boolean &fn){ return count_if(all(v),fn); }
template <class T> inline T Count(V<T>& v, ll x){ if(!is_sorted(all(v))) Sort(v); return UB(v,x)-LB(v,x); }
template <class T> inline T IP(const V<T>& v, const V<T>& u, T init){ return inner_product(all(v),u.begin(),init); }
inline vi iot(int n, ll init=0){ vi a(n); iota(all(a),init); return a; }
template <class T, class U, class F> inline V<T> trans(const V<U>& v, const F &fn){ V<T> res; transform(all(v),back_inserter(res),fn); return res; }
template <class T, class U> inline int ers(T& v, const U x){ v.erase(remove(all(v),x),v.end()); return v.size(); }
template <class T, class Boolean=bool> int ersif(T& v, const Boolean &fn){ v.erase(remove_if(all(v),fn),v.end()); return v.size(); }
template <class T> inline int unq(T& v){ if(!is_sorted(all(v))) Sort(v); v.erase(unique(all(v)),v.end()); return v.size(); }
template <class T> inline T cp(const T& v){ T res; copy(all(v),back_inserter(res)); return res; }
template <class T> inline T cp(const T& v, const int a, const int b){ T res; copy(all(v,a,b),back_inserter(res)); return res; }
template <class T> inline void rtt(T& s, const int idx){ const int id=zia_qu::Mod<int>(idx,s.size()); rotate(all(s,id),s.end()); }
template <class T> inline void rtt(T& s, const int a, const int b, const int c){ rotate(all(s,a,b),s.end()-c); }
template <class T> inline T setdif(const T& s, const T& t){ assert(is_sorted(all(s))&&is_sorted(all(t))); T res; set_difference(all(s),all(t),inserter(res,end(res))); return res; }
template <class T> inline T setsum(const T& s, const T& t){ assert(is_sorted(all(s))&&is_sorted(all(t))); T res; set_union(all(s),all(t),inserter(res,end(res))); return res; }
template <class T> inline T setmul(const T& s, const T& t){ assert(is_sorted(all(s))&&is_sorted(all(t))); T res; set_intersection(all(s),all(t),inserter(res,end(res))); return res; }
template <class T> inline V<T> adf(const V<T>& v){ V<T> a; adjacent_difference(all(v),back_inserter(a)); rtt(a,1); a.pop_back(); return a; }
template <class T, class F> inline V<T> isum(const V<T> &v, const F &fn){ V<T> s{0}; inclusive_scan(all(v),back_inserter(s),fn); return s; }
template <class T> inline V<T> rext(const V<T>& v, const int size){ V<T> res; sample(all(v),back_inserter(res),size,Random()); return res; }
template <class T> inline T rext(const V<T>& v){ V<T> res; sample(all(v),back_inserter(res),1,Random()); return res.front(); }
template <class T> inline ll vsum(const T &v){ return accumulate(all(v),0LL); }
template <class T> inline ll vsum(const T &v, ll a, ll b){ return accumulate(all(v,a,b),0LL); }
template <class T> inline ld vdsum(const T &v){ return accumulate(all(v),0.0L); }
template <class T> inline ld vdsum(const T &v, ll a, ll b){ return accumulate(all(v,a,b),0.0L); }
template <class T> inline ll vmul(const T &v){ return accumulate(all(v),1LL,[](ll acc,ll i){ return acc*i; }); }
template <class T> inline ll vmul(const T &v, ll a, ll b){ return accumulate(all(v,a,b),1LL,[](ll acc,ll i){ return acc*i; }); }
template <class T> inline ld vdmul(const T &v){ return accumulate(all(v),1.0L,[](ll acc,ll i){ return acc*i; }); }
template <class T> inline ld vdmul(const T &v, ll a, ll b){ return accumulate(all(v,a,b),1.0L,[](ll acc,ll i){ return acc*i; }); }
} // Lady s&y

namespace Heileden {
template <class T> inline V<T> div(const T n) {
    V<T> d;
    sqrp(i,1,n) {
        if(n%i==0) {
            d.emplace_back(i);
            if(i*i!=n) d.emplace_back(n/i);
        }
    }
    Lady_sANDy::Sort(d);
    return d;
}
inline bool is_prime(const ul n) {
    if(n==1) return 0;
    sqrp(i,2,n) if(n%i==0) return 0;
    return 1;
}
template <class T> inline V<PP<T>> prmfct(T n) {
    V<PP<T>> res;
    sqrp(i,2,n) {
        if(n%i) continue;
        T tmp=0;
        while(n%i==0) {
            tmp++;
            n/=i;
        }
        res.emplace_back(i,tmp);
    }
    if(n!=1) res.emplace_back(n,1);
    return res;
}
struct p_table {
    vb SoE;
    p_table(int n): SoE(n+1,1){
        SoE[0]=SoE[1]=0;
        rep(i,2,n) {
            if(!SoE[i]) continue;
            rep(j,i*i,n,i) SoE[j] = 0;
        }
    }
    vi get() const {
        vi p;
        rep(i,2,SoE.size()-1) if(SoE[i]) p.emplace_back(i);
        return p;
    }
};
struct p_fact {
    vi spf;
    p_fact(int n): spf(n + 1){
        iota(all(spf),0);
        sqrp(i,2,n) {
            if(spf[i]==i) {
                rep(j,i*i,n,i) {
                    if(spf[j]==j) spf[j]=i;
                }
            }
        }
    }
    map<int,int> get(int n) {
        map<int,int> m;
        while(n!=1) {
            m[spf[n]]++;
            n/=spf[n];
        }
        return m;
    }
};
struct asum {
    vi s;
    asum(const vi& v): s{0} { partial_sum(all(v),back_inserter(s)); }
    vi get() const { return s; }
    // [l, r]
    ll query(int l, int r) const { return s[r]-s[l]; }
};
template <class T, class Boolean=bool> inline T bins(T ok, T ng, const Boolean &fn, const ld eps = 1) {
    while(abs(ok-ng)>eps) {
        T mid=(ok+ng)/2;
        (fn(mid)?ok:ng) = mid;
    }
    return ok;
}
template <class T> inline V<T> press(const V<T>& v) {
    V<T> res,cp=v;
    Lady_sANDy::unq(cp);
    each(el,v) res.emplace_back(Lady_sANDy::LB(cp,el));
    return res;
}
template <class T> inline V<T> press(V<T> &c1, V<T> &c2) {
    V<T> res;
    const int n = c1.size();
    rep(n) {
        for(T d = 0; d < 1; d++) {
            T tc1 = c1[i]+d;
            T tc2 = c2[i]+d;
            res.emplace_back(tc1);
            res.emplace_back(tc2);
        }
    }
    Lady_sANDy::unq(res);
    rep(n) {
        c1[i]=Lady_sANDy::LB(res,c1[i]);
        c2[i]=Lady_sANDy::LB(res,c2[i]);
    }
    return res;
}
inline vs rtt(const vs &s) {
    const int h=s.size(), w=s.front().size();
    vs t(w,string(h,{}));
    rep(h) rep(j,w) t[j][i]=s[i][j];
    rep(w) Lady_sANDy::rev(t[i]);
    return t;
}
template <class T> inline V<V<T>> rtt(const V<V<T>>& v) {
    const int h=v.size(), w=v.front().size();
    V<V<T>> res(w,V<T>(h));
    rep(h) rep(j,w) res[j][i]=v[i][j];
    rep(w) Lady_sANDy::rev(res[i]);
    return res;
}
template <class T> T factor(T n, const T mod=0) {
    T res=1;
    while(n>0) {
        res*=n--;
        if(mod) res%=mod;
    }
    return res;
}
template <class T=ll> T perm(T n, const T r, const T mod=0) {
    const T tmp=n;
    T res=1;
    while(n>tmp-r) {
        res*=n--;
        if(mod) res%=mod;
    }
    return res;
}
template <class T=ll> T binom(T n, const T r, const T mod=0) {
    if(r < 0 || n < r) return 0;
    T res = 1;
    rep(i,1,r) {
        res*=n--;
        if(mod) res%=mod;
        res/=i;
        if(mod) res%=mod;
    }
    return res;
}
inline bool is_int(const ld n){ ll r=floor(n); return r==n; }
inline bool is_sqr(const ll n){ return is_int(sqrtl(n)); }
/* grundy sample
template <class T> inline bool grundy(const V<T> &v) {
    ll res=0;
    each(el,v) res^=el;
    return res!=0;
}//*/
} // Heileden


// --------------------------------------------------------------------------------------------------------------

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
    INT(n,m);
    VEC(ll,a,n);
    Sort(a);
    vi s{0};
    rep(n) {
        s.emplace_back(s[i]+sqr<ll>(a[i+1]-a[i]));
    }
    Sort(s);
    ll ans=LINF;
    rep(n) {
        if(i+m-1<n) {
            chmin(ans,s[i+m-1]-s[i]);
        }
    }
    out(ans);
}