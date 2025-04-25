import std;
import core.bitop;

void main() {
    int x, y;
    readf("%d %d", x, y);
    writeln(yes(x == y));
}

string yes(bool condition) pure @nogc nothrow @safe {
    return condition ? "Yes" : "No";
}