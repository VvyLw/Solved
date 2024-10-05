import os { input }
import math { min }

fn main() {
	s := input('')
	t := input('')
	if s == t {
		println(0)
		return
	}
	n := min(s.len, t.len)
	for i in 0 .. n {
		if s[i] != t[i] {
			println(i + 1)
			return
		}
	}
	println(n + 1)
}
