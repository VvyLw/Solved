import os { input }

fn main() {
	n := input('').int()
	mut flg := false
	for _ in 0 .. n - 1 {
		s := input('')
		if flg && s == 'sweet' {
			println('No')
			return
		}
		flg = s == 'sweet'
	}
	println('Yes')
}
