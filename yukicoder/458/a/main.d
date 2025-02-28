import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    auto s = readln.chomp.dup;
    ulong j = 0;
    foreach(i, c; s) {
        if(isDigit(c)) {
            j = i;
            break;
        }
    }
    assert(j != -1);
    writeln(s[0..j].reverse ~ s[j..$]);
}