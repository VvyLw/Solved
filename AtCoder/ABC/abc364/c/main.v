import os { input }

fn main() {
	nxy := input('').split(' ').map(it.i64())
	n, x, y := int(nxy[0]), nxy[1], nxy[2]
	mut a := input('').split(' ').map(it.int())
	mut b := input('').split(' ').map(it.int())
	a.sort(a > b)
	b.sort(a > b)
	mut p, mut q := i64(0), i64(0)
	for i in 0 .. n {
		p += a[i]
		q += b[i]
		if p > x || q > y {
			println(i + 1)
			return
		}
	}
	println(n)
}
