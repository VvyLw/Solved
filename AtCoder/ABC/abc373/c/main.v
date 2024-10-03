import os { input }
import arrays { max }

fn main() {
	_ := input('')
	a := input('').split(' ').map(it.int())
	b := input('').split(' ').map(it.int())
	println(max(a)! + max(b)!)
}
