import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const n = readln.chomp.to!int;
    const s = readln.chomp;
    if(n & 1) {
        writeln("No");
        return;
    }
    writeln("Yes");
    char[] a, b;
    foreach(i; 0..n) {
        if(i & 1) {
            a ~= s[i];
        } else {
            b ~= s[i];
        }
    }
    writeln(b, " ", a);
}