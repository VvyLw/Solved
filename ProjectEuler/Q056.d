import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    auto ans = 0;
    foreach(a; 1..100) {
        foreach(b; 1..100) {
            const x = (BigInt(a) ^^ b).to!string;
            int ret = 0;
            foreach(c; x) {
                ret += c - '0';
            }
            ans = max(ans, ret);
        }
    }
    writeln(ans);
}