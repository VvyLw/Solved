import os { input }
import math { abs }

fn main() {
	n := input('').int()
	mut l := []int{}
	mut r := []int{}
	for _ in 0 .. n {
		x := input('').split(' ')
		a, s := x[0].int(), x[1]
		if s == 'L' {
			l << a
		} else {
			r << a
		}
	}
	mut ret := 0
	for i in 1 .. l.len {
		ret += abs(l[i] - l[i - 1])
	}
	for i in 1 .. r.len {
		ret += abs(r[i] - r[i - 1])
	}
	println(ret)
}
