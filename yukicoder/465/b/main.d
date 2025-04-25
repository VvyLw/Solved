import std;
import core.bitop;

void main() {
    const n = readln.chomp.to!int;
    auto a = new string[n];
    foreach(i; 0..n) {
        a[i] = readln.chomp;
    }
    int ret = 0;
    foreach(e; a) {
        ret += e.count('#');
    }
    writeln(yes(n % 2 == 1 || ret % 2 == 0));
}

string yes(const bool b) pure @nogc nothrow @safe {
    return b ? "Yes" : "No";
}