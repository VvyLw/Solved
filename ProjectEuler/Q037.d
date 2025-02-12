import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const n = 1_000_001;
    auto isPrime = new bool[n];
    isPrime[] = true;
    isPrime[0] = isPrime[1] = false;
    foreach(i; 2U..n) {
        if(!isPrime[i]) {
            continue;
        }
        foreach(j; iota(i * i, n, i)) {
            isPrime[j] = false;
        }
    }
    int[] p;
    foreach(i; 11..n-1) {
        if(isPrime[i]) {
            const s = i.to!string;
            const m = s.length;
            if(iota(1, m).all!(k => isPrime[s[0..k].to!int] && isPrime[s[k..$-0].to!int])) {
                p ~= i;
            }
        }
    }
    p.sort;
    p = p.uniq.array;
    writeln(p);
    assert(p.length == 11);
    writeln(p.sum);
}