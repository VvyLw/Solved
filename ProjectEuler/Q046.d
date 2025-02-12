import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const n = 50_001;
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
    foreach(i; 2..n) {
        if(isPrime[i]) {
            p ~= i;
        }
    }
    auto ret = int.max;
    foreach(i; iota(9, n, 2)) {
        if(isPrime[i]) {
            continue;
        }
        bool ok = true;
        foreach(e; p) {
            foreach(j; 1..100) {
                const x = e + 2 * j * j;
                ok &= x != i;
            }
        }
        if(ok) {
            ret = min(ret, i);
        }
    }
    writeln(ret);
}