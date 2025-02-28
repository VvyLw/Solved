import std;
import core.bitop;
import core.checkedint;
import core.time;

void main() {
    int n, h;
    readf("%d %d\n", n, h);
    auto ims = new int[h + 1];
    foreach(_; 0..n) {
        int a, b;
        readf("%d %d\n", a, b);
        ims[a]++;
        ims[b + 1]--;
    }
    foreach(i; 0..h) {
        ims[i + 1] += ims[i];
    }
    writeln(maxElement(ims));
}