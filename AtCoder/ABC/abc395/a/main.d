import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const n = readln.chomp.to!int;
    const a = readln.split.to!(int[]);
    writeln(isSorted(a) && a.uniq.array.length == n ? "Yes" : "No");
}