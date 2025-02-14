import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    const x = readln.chomp;
    const y = readln.chomp;
    const l = x.length - y.length;
    if(l == 0 || l == 1) {
        char[] ret;
        foreach(i; 0..x.length) {
            ret ~= x[i];
            if(i < y.length) {
                ret ~= y[i];
            }
        }
        writeln(ret);
        return;
    }
    writeln("?");
}