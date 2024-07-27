import os { input }

fn main() {
	hw := input('').split(' ').map(it.int())
	st := input('').split(' ').map(it.int())
	h, w := hw[0], hw[1]
	mut s, mut t := st[0] - 1, st[1] - 1
	mut c := [][]string{len: h}
	for i in 0 .. h {
		c[i] = input('').split('')
	}
	x := input('').split('')
	for y in x {
		if y == 'L' {
			if 0 <= t - 1 && t - 1 < w && c[s][t - 1] == '.' {
				t--
			}
		} else if y == 'R' {
			if 0 <= t + 1 && t + 1 < w && c[s][t + 1] == '.' {
				t++
			}
		} else if y == 'U' {
			if 0 <= s - 1 && s - 1 < w && c[s - 1][t] == '.' {
				s--
			}
		} else {
			if 0 <= s + 1 && s + 1 < w && c[s + 1][t] == '.' {
				s++
			}
		}
	}
	println('${s + 1} ${t + 1}')
}
