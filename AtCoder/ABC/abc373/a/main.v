import os { input }

fn main() {
	mut ret := 0
	for i in 0 .. 12 {
		s := input('')
		if s.len == i + 1 {
			ret++
		}
	}
	println(ret)
}
