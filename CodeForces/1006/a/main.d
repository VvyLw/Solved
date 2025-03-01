import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const t = readln.chomp.to!int;
    foreach(i; 0..t) {
        writeln(solve);
    }
}

int solve() {
    int n, k, p;
    readf("%d %d %d\n", n, k, p);
    if(abs(k) > n * p) {
        return -1;
    }
    return cast(int)ceil(cast(double)abs(k) / p);
}