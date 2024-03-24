import std.stdio: readf, readln, writeln;
import std.string: split;
import std.conv: to;
import std.algorithm: sort, uniq;

void main() {
    int n, k;
    readf("%d %d\n", &n, &k);
    auto a = readln.split.to!(int[]);
    sort(a);
    auto ans = k * (k + 1L) / 2;
    foreach(e; a.uniq) {
        if(e > k) {
            continue;
        }
        ans -= e;
    }
    writeln(ans);
}