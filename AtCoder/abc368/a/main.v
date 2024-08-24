import os { input }
import arrays { rotate_right }

fn main() {
	nk := input('').split(' ').map(it.int())
	_, k := nk[0], nk[1]
	mut a := input('').split(' ').map(it.int())
	rotate_right(mut a, k)
	println(a.map(it.str()).join(' '))
}
