import os { input }

fn main() {
	n := input('').int()
	a := input('').split(' ').map(it.i64())
	for i in 0 .. n - 2 {
		if a[i + 1] * a[i + 1] != a[i] * a[i + 2] {
			println('No')
			return
		}
	}
	println('Yes')
}