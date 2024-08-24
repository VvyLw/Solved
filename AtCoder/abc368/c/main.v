import os { input }
import math { min }

fn main() {
	_ := input('')
	mut h := input('').split(' ').map(it.int())
	mut t := i64(0)
	for mut e in h {
		for t % 3 != 2 && e > 0 {
			t++
			e--
		}
		if e > 0 {
			e -= 3
			t++
		}
		if e <= 0 {
			continue
		}
		t += *e / 5 * 3
		t += min(*e % 5, 3)
	}
	println(t)
}
