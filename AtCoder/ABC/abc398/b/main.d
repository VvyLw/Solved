import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    auto a = readln.split.to!(int[]).map!"a - 1";
    int[] cnt = new int[13], cnt2 = new int[8];
    foreach(e; a) {
        cnt[e]++;
    }
    foreach(e; cnt) {
        if(e > 0) {
            cnt2[e]++;
        }
    }
    int c = 0;
    foreach(i; 2..8) {
        if(cnt2[i] > 0) {
            c++;
        }
    }
    writeln(yes(c >= 2));
}

pragma(inline)
string yes(bool b) pure @nogc nothrow @safe {
    return b ? "Yes" : "No";
}