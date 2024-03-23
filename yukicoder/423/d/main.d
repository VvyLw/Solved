import std.stdio: readf, readln, writeln;
import std.conv: to;
import std.string: split;
struct PrefixSum(T) {
import std.algorithm.iteration: cumulativeFold;
import std.array: array, insertInPlace;
private:
    int n;
    bool not_built;
    T[] s;
public:
    this(const int n) {
        this.n = n;
        not_built = true;
        s = new T[n + 1];
    }
    this(const T[] a) {
        s = cumulativeFold!"a + b"(a, cast(T)0).array;
        insertInPlace(s, 0, 0);
    }
    T[] get(){ return s; }
    T sum(const int l, const int r) const { return s[r] - s[l]; }
    void add(const int l, const int r, const T x) {
        assert(not_built);
        s[l] += x;
        s[r] -= x;
    }
    T[] build() {
        assert(not_built);
        auto res = cumulativeFold!"a + b"(s).array;
        not_built = false;
        return res[0..n];
    }
}
void chmax(T, U)(ref T a, const U b) {
    if(a < b) {
		a = b;
	}
}
void main() {
    int n, h;
    readf("%d %d\n", &n, &h);
    const a = readln.split.to!(int[]);
    const b = readln.split.to!(long[]);
    auto ps = new PrefixSum!long(b);
    long ans = 0, s = 0, t = 0;
    for(int l = 0, r = 0; l < n; ++l) {
        while(r < n && t + (r - l + 1) * b[r] <= h) {
            s += a[r];
            t += (r - l + 1) * b[r];
            r++;
        }
        if(l == r) {
            r++;
        } else {
            chmax(ans, s);
            s -= a[l];
            t -= ps.sum(l, r);
        }
    }
    writeln(ans);
}