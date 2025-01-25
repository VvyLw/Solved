import os { input }
import math { max, min }

const inf = 1 << 30

fn main() {
	hw := input('').split(' ').map(it.int())
	h, w := hw[0], hw[1]
	mut s := []string{len: h}
	for i in 0 .. h {
		s[i] = input('')
	}
	mut max_x, mut min_x, mut max_y, mut min_y := -1, inf, -1, inf
	for i in 0 .. h {
		for j in 0 .. w {
			if s[i][j].ascii_str() == '#' {
				max_x = max(max_x, i)
				min_x = min(min_x, i)
				max_y = max(max_y, j)
				min_y = min(min_y, j)
			}
		}
	}
	for i in min_x .. max_x + 1 {
		for j in min_y .. max_y + 1 {
			if s[i][j].ascii_str() == '.' {
				println('No')
				return
			}
		}
	}
	println('Yes')
}
