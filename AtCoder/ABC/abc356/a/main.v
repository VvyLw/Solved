import os{input}
fn main() {
	nlr:=input('').split(' ').map(it.int())
	n,l,r:=nlr[0],nlr[1]-1,nlr[2]
	a:=[]int{len:n,init:index+1}
	mut b:=[]int{}
	b<<a[0..l]
	b<<a[l..r].reverse()
	b<<a[r..n]
	println(b.map(it.str()).join(' '))
}