import os { input }

fn main() {
	n := input('').int()
	a := input('').split(' ').map(it.int())
	mut ret := i64(0)
	mut r := 2
	for l in 0 .. n {
		for r < n && a[r] - a[r - 1] == a[l + 1] - a[l] {
			r++
		}
		if r < l + 2 {
			r = l + 2
		} else {
			ret += r - l - 2
		}
	}
	println(ret + 2 * n - 1)
}
