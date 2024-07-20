import os { input }
import math { ceil, powi }

fn main() {
	n := input('').i64() - 1
	mut s, mut m := i64(0), 1
	for {
		x := 9 * powi(10, (m - 1) / 2)
		if s + x >= n {
			break
		}
		s += x
		m++
	}
	r, st := n - s, powi(10, int(ceil(f64(m) / 2)) - 1)
	t := (st + r - 1).str()
	println(t + t.reverse().substr(m & 1, t.len))
}
