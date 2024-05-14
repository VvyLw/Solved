import os{input}
import arrays{sum}
import math{abs}
fn main() {
	n:=input('').int()
	mut a:=input('').split(' ').map(it.i64())
	a.sort()
	x:=int(1e8)
	mut res:=i64(0)
	for el in a {
		i:=lb(a,x-el)
		res+=n-i
		if 2*el>=x {
			res--
		}
	}
	res/=2
	println(sum(a)!*(n-1)-res*x)
}
fn lb[T](a []T, b T) int {
	mut ok,mut ng:=a.len,-1
	for abs(ok-ng)>1 {
		mid:=(ok+ng)/2
		if a[mid]>=b {
			ok=mid
		} else {
			ng=mid
		}
	}
	return ok
}