import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const t = readln.chomp.to!int;
    foreach(_; 0..t) {
        writeln(solve);
    }
}

long solve() {
    const n = readln.chomp.to!int;
    const s = readln.chomp;
    int x = 0, y = 0;
    foreach(c; s) {
        if(c == '-') {
            x++;
        } else {
            y++;
        }
    }
    return cast(long)(x / 2) * (x - x / 2) * y;
}