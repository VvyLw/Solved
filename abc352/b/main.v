import os{input}
fn main() {
	s:=input('').split('')
	t:=input('').split('')
	mut a:=[]int{}
	mut i:=0
	mut j:=0
	for j<t.len {
		if s[i]==t[j] {
			a<<j+1
			i++
		}
		j++
	}
	println(a.map(it.str()).join(' '))
}