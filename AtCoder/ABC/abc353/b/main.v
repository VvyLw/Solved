import os{input}
fn main() {
	nk:=input('').split(' ').map(it.int())
	k:=nk[1]
	a:=input('').split(' ').map(it.int())
	mut ans,mut now:=0,0
	for e in a {
		if now+e<=k {
			now+=e
		} else {
			ans++
			now=e
		}
		//eprintln('$now $ans')
	}
	println(ans+1)
}
