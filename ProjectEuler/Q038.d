import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    auto a = iota(1, 10).array;
    long ret = 0;
    do {
        foreach(k; 1..5) {
            string s;
            int i = 1;
            const x = iota(0, k).map!(j => a[j].to!string).join.to!int;
            while(s.length < 9) {            
                s ~= to!string(x * i);
                i++;
            }
            if(s.length == 9) {
                const z = s.to!long;
                if(z == a.map!(to!string).join.to!long) {
                    ret = max(ret, z);
                }
            }
        }
    } while(a.nextPermutation);
    writeln(ret);
}