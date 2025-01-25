import os { input }

fn main() {
	mut a := input('').split(' ').map(it.int())
	b := []int{len: 5, init: index + 1}
	assert a.len == 5
	for i in 0 .. 4 {
		a[i], a[i + 1] = a[i + 1], a[i]
		if a == b {
			println('Yes')
			return
		}
		a[i], a[i + 1] = a[i + 1], a[i]
	}
	println('No')
}