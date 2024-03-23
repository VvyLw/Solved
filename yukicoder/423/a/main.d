import std.stdio: readf, writeln;
import std.algorithm: max;

void main() {
    int a, b, o, ab;
    readf("%d %d %d %d\n", &a, &b, &o, &ab);
    writeln(max(a, b) + o + ab);
}