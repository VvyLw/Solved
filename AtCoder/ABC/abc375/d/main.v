import os { input }

fn main() {
	s := input('')
	n := s.len
	mut t := [][]i64{len: n + 1, init: []i64{len: 26}}
	for i in 0 .. n {
		for j in 0 .. 26 {
			t[i + 1][j] = t[i][j]
		}
		t[i + 1][s[i] - 'A'[0]]++
	}
	mut ret := i64(0)
	for i in 1 .. n - 1 {
		for j in 0 .. 26 {
			ret += t[i][j] * (t[n][j] - t[i + 1][j])
		}
	}
	println(ret)
}
