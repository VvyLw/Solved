import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const n = readln.chomp.to!double;
    writeln(cast(int)sqrt(n));
}