import os{input}

fn main() {
	_:=input('')
	a:=input('').split(' ').map(it.int())
	mut ini,mut ans:=0,-1
	for i,e in a {
		if i==0 {
			ini=e
		} else if ini<e {
			ans=i+1
			break
		}
	}
	println(ans)
}