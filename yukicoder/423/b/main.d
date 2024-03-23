import std.stdio: readln, writeln;
import std.string: chomp;
import std.conv: to;

void main() {
    const n = readln.chomp.to!int;
    auto s = new string[n];
    foreach(i; 0..n) {
        s[i] = readln.chomp;
    }
    auto cnt = 0;
    foreach(i; 0..n) {
        auto r = new int[2];
        foreach(j; 0..n) {
            if(s[i][j] == 'A') {
                r[0]++;
            } else if(s[i][j] == '.') {
                r[1]++;
            }
        }
        if(r[0] == n - 1 && r[1] == 1) {
            cnt++;
        }
    }
    foreach(i; 0..n) {
        auto c = new int[2];
        foreach(j; 0..n) {
            if(s[j][i] == 'A') {
                c[0]++;
            } else if(s[j][i] == '.') {
                c[1]++;
            }
        }
        if(c[0] == n - 1 && c[1] == 1) {
            cnt++;
        }
    }
    auto x = new int[2];
    foreach(i; 0..n) {
        if(s[i][i] == 'A') {
            x[0]++;
        } else if(s[i][i] == '.') {
            x[1]++;
        }
    }
    if(x[0] == n - 1 && x[1] == 1) {
        cnt++;
    }
    x[] = 0;
    foreach(i; 0..n) {
        if(s[i][n - 1 - i] == 'A') {
            x[0]++;
        } else if(s[i][n - 1 - i] == '.') {
            x[1]++;
        }
    }
    if(x[0] == n - 1 && x[1] == 1) {
        cnt++;
    }
    writeln(cnt);
}