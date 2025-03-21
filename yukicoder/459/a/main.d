import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    long x, n;
    readf("%d %d\n", x, n);
    const z = abs(x);
    long ok = 1, ng = cast(long)1e10;
    while(abs(ok - ng) > 1) {
        const y = (ok + ng) / 2;
        if(y * (y + 1) / 2 <= z) {
            ok = y;
        } else {
            ng = y;
        }
    }
    const p = ok * (ok + 1) / 2;
    if(x > 0) {
        x -= p;
    } else {
        x += p;
    }
    const q = cast(long)ceil(cast(double)(n - ok) / 2);
    if(q % 2 == 0) {
        x += q;
    } else {
        x -= q;
    }
    writeln(x);
}