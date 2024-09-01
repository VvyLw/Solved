import os { input }

fn main() {
	ab := input('').split(' ').map(it.int())
	a, b := ab[0], ab[1]
	if a == b {
		println(1)
	} else {
		println(2 + if (a + b) % 2 == 0 { 1 } else { 0 })
	}
}
