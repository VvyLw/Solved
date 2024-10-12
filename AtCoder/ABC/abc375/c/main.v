import os { input }
import math.stats { min }

fn main() {
	n := input('').int()
	mut a := []string{len: n}
	for i in 0 .. n {
		a[i] = input('')
	}
	mut b := [][]string{len: n, init: []string{len: n}}
	for i in 0 .. n {
		for j in 0 .. n {
			d := min([i + 1, j + 1, n - i, n - j])
			mut x, mut y := i, j
			for _ in 0 .. d % 4 {
				x, y = y, n - 1 - x
			}
			b[x][y] = a[i][j].ascii_str()
		}
	}
	for s in b {
		println(s.join(''))
	}
}