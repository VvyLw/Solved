import os { input }

fn main() {
	n := input('').int()
	mut a := [][]int{len: n}
	for i in 0 .. n {
		a[i] = input('').split(' ').map(it.int())
	}
	mut i := a.first().first()
	for j in 0 .. n {
		i--
		if i >= j {
			i = a[i][j]
		} else {
			i = a[j][i]
		}
	}
	println(i)
}
