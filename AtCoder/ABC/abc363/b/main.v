import os { input }
import math { max, min }

fn main() {
	ntp := input('').split(' ').map(it.int())
	n, t, p := ntp[0] - 1, ntp[1], ntp[2] - 1
	mut l := input('').split(' ').map(it.int())
	l.sort(a > b)
	x := l[min(p, n)]
	println(max(0, t - x))
}
