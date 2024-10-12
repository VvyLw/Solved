import os { input }
import math { hypot }

fn main() {
	n := input('').int()
	mut x, mut y := 0, 0
	mut ret := f64(0)
	for _ in 0 .. n {
		l := input('').split(' ').map(it.int())
		ret += hypot(l[0] - x, l[1] - y)
		x, y = l[0], l[1]
	}
	ret += hypot(x, y)
	println(ret)
}