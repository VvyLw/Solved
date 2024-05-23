import arrays{sum}
import math{factoriali}
fn main() {
	n:=1000000
	mut s:=0
	for i in 3..n+1 {
		if i==sum(i.str().split('').map(factoriali(it.int())))! {
			s+=i
		}
	}
	println(s)
}