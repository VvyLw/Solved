import os { input }
import arrays { max, sum }
import math { min }

fn main() {
	_ := input('')
	a := input('').split(' ').map(it.int())
	s := sum(a)!
	println(min(s / 2, s - max(a)!))
}
