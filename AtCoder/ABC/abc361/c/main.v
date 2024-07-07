import os { input }
import math { min }

fn main() {
	nk := input('').split(' ').map(it.int())
	n, k := nk[0], nk[1]
	mut a := input('').split(' ').map(it.int())
	a.sort()
	mut res := 1 << 30
	for i in 0 .. k + 1 {
		chmin(mut res, a[n - k - 1 + i] - a[i])
	}
	println(res)
}

fn chmin[T, U](mut a T, b U) bool {
	jdg := a > b
	a = min(a, b)
	return jdg
}