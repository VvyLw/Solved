import os { input }
import math { max }
import arrays

fn main() {
	n := input('').int()
	a := input('').split(' ').map(it.int())
	mut dp := [][]i64{len: n + 1, init: []i64{len: 2}}
	for i in 0 .. n {
		dp[i + 1][0] = max(dp[i][0], dp[i][1] + a[i])
		if i == 0 {
			continue
		}
		dp[i + 1][1] = max(dp[i][1], dp[i][0] + a[i] * 2)
	}
	$if debug {
		dump(dp)
	}
	println(arrays.max(dp[n])!)
}
