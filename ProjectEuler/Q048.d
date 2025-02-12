import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const n = 1000;
    const m = cast(ulong)1e10;
    ulong ret = 0;
    foreach(i; 1..n + 1) {
        ulong k = i;
        foreach(_; 0..i - 1) {
            k *= i;
            k %= m;
        }
        ret += k;
        ret %= m;
    }
    writeln(ret);
}