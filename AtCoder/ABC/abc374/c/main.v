import os { input }
import arrays { sum }
import math { max, min }

fn main() {
	n := input('').int()
	k := input('').split(' ').map(it.int())
	s := sum(k)!
	mut ret := i64(u64(1) << 60)
	for i in 0 .. 1 << n {
		mut t := 0
		for j in 0 .. n {
			if (i >> j) & 1 == 1 {
				t += k[j]
			}
		}
		ret = min(ret, max(t, s - t))
	}
	println(ret)
}
