import std;
import core.bitop;
import core.checkedint;
import core.time;

const a = [1, 2, 5, 10, 20, 50, 100, 200];

void main() {
    const n = 201;
    auto dp = new int[n];
    dp[0] = 1;
    foreach(e; a) {
        foreach(i; e..n) {
            dp[i] += dp[i - e];
        }
    }
    writeln(dp[$-1]);
}