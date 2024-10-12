import os { input }

fn main() {
	n := input('').int()
	s := input('')
	if n < 3 {
		println(0)
		return
	}
	mut cnt := 0
	for i in 0 .. n - 2 {
		if s[i..i + 3] == '#.#' {
			cnt++
		}
	}
	println(cnt)
}