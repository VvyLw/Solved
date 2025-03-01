import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const n = readln.chomp.to!int;
    auto s = new char[][](n, n);
    foreach(i; 0..n) {
        foreach(j; 0..n) {
            if(minElement([i, j, n - i - 1, n - j - 1]) % 2 == 0) {
                s[i][j] = '#';
            } else {
                s[i][j] = '.';
            }
        }
    }
    writeln(s.join('\n'));
}