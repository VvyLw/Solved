import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
	const a = readln.split.to!(int[]);
	const b = readln.split.to!(int[]);
    const c = (a ~ b).to!(long[]);
    const g = c.fold!(gcd);
    if(g == 0) {
        writeln("0 0");
    } else {
        writeln(g, " ", abs(c[0] * c[3] - c[1] * c[2]) / g);
    }
}