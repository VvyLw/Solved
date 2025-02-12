import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const n = 1_000_000;
    auto pt = new PrimeTable(n);
    auto p = pt.prime;
    const q = pt.table;
    const x = p.length;
    int m = 0, ret = 0;
    foreach(l; 0..x) {
        foreach(r; l + m..x) {
            const s = p[l..r].sum;
            if(s >= n) {
                break;
            }
            if(q[s]) {
                m = cast(int)(r - l);
                ret = max(ret, s);
            }
        }
    }
    writeln(ret);
}

class PrimeTable {
    private bool[] isPrime;
    private int n;
    this(const int n) {
        this.n = n;
        isPrime = new bool[n + 1];
        isPrime[] = true;
        isPrime[0] = isPrime[1] = false;
        foreach(i; 2U..n + 1) {
            if(!isPrime[i]) {
                continue;
            }
            foreach(j; iota(i * i, n + 1, i)) {
                isPrime[j] = false;
            }
        }
    }
    bool[] table() pure nothrow @safe @nogc {
        return isPrime;
    }
    int[] prime() pure const nothrow @safe {
        int[] p;
        foreach(i; 2..n + 1) {
            if(isPrime[i]) {
                p ~= i;
            }
        }
        return p;
    }
}