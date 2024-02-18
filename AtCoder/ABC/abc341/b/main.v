import os{input}
fn main() {
	n:=input('').int()
	mut a:=input('').split(' ').map(it.i64())
	for i in 0..n-1 {
		x:=input('').split(' ').map(it.int())
		y:=a[i]/x[0]
		a[i+1]+=x[1]*y
	}
	println(a[n-1])
}