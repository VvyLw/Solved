import std.stdio: readf, readln, writeln;
import std.string: split;
import std.conv: to;
import std.algorithm.searching: count;

void main() {
    int w, b;
    readf("%d %d\n", &w, &b);
    if(w == 0 && b == 0) {
        writeln("Yes");
        return;
    }
    const string s = "wbwbwwbwbwbw";
    string t;
    foreach(_; 0..20) {
        t ~= s;
    }
    const n = t.length;
    foreach(i; 0..n) {
        foreach(j; i..n) {
            const u = t[i..j];
            const cnt = count(u, 'w');
            if(w == cnt && b == u.length - cnt) {
                writeln("Yes");
                return;
            }
        }
    }
    writeln("No");
}