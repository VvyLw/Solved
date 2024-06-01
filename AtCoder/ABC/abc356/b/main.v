import os{input}
fn main() {
	nm:=input('').split(' ').map(it.int())
	n,m:=nm[0],nm[1]
	a:=input('').split(' ').map(it.int())
	mut x:=[][]int{len:n}
	for i in 0..n {
		x[i]=input('').split(' ').map(it.int())
	}
	mut ok:=true
	for i in 0..m {
		mut res:=0
		for j in 0..n {
			res+=x[j][i]
		}
		ok=ok && res>=a[i]
	}
	println(if ok {"Yes"} else {"No"})
}