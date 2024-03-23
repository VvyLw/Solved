import std.stdio: readf, writeln;
import core.stdc.stdlib: exit;
import core.checkedint: adds, muls;

bool chk(const long x){ return x > cast(long)1e18 || x < 0; }
void chmax(T, U)(ref T a, const U b) {
    if(a < b) {
		a = b;
	}
}
void main() {
    int n, k;
    long p;
    readf("%d %d %d\n", &n, &p, &k);
	auto dp = new long[][](n + 1, n + 1);
    dp[0][0] = p;
    foreach(i; 0..n) {
		int t, b;
		readf("%d %d\n", &t, &b);
		bool overflow;
        foreach(j; 0..n) {
            if(t == 1) {
                const x = adds(dp[i][j], b, overflow);
				if(overflow || chk(x)) {
					writeln(-1);
					exit(0);
				}
				chmax(dp[i + 1][j + 1], x);
			} else {
				const x = muls(dp[i][j], 2, overflow);
				if(overflow || chk(x)) {
					writeln(-1);
					exit(0);
				}
				chmax(dp[i + 1][j + 1], x);
			}
			chmax(dp[i + 1][j], dp[i][j]);
        }
    }
    writeln(dp[n][k]);
}