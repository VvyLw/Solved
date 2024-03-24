import std.stdio: readln, writeln;
import std.conv: to;
import std.string: split, chomp;
import std.array: join;

void main() {
    const n = readln.chomp.to!int;
    const a = readln.split.to!(int[]);
    auto b = new int[](n - 1);
    foreach(i; 0..n - 1) {
        b[i] = a[i] * a[i + 1];
    }
    writeln(b.to!(string[]).join(" "));
}