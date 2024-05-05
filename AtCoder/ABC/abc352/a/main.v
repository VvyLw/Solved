import os{input}
fn main() {
	l:=input('').split(' ').map(it.int())
	mut x:=l[1]
	mut y:=l[2]
    z:=l[3]
	if x>y {
		x,y=y,x
	}
	println(if x<=z && z<=y {"Yes"} else {"No"})
}