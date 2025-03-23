import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const n = readln.chomp.to!int;
    auto s = new char[n];
    s []= '-';
    const k = (n - 1) / 2;
    s[k] = '=';
    if(n % 2 == 0) {
        s[k + 1] = '=';
    }
    writeln(s);
}