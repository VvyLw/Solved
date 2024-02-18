import os{input}
fn main() {
	l:=input('').split(' ').map(it.int())
	h:=l[0]
	w:=l[1]
	t:=input('').split('')
	mut s:=[][]string{len:h}
	for i in 0..h {
		s[i]=input('').split('')
	}
	mut cnt:=0
	for i in 0..h {
		for j in 0..w {
			if s[i][j]=='#' {
				continue
			}
			mut x:=i
			mut y:=j
			mut ok:=true
			for c in t {
				if c=='L' {
					y--
				} else if c=='R' {
					y++
				} else if c=='U' {
					x--
				} else {
					x++
				}
				if 0<=x && x<h && 0<=y && y<w {
					ok=ok && s[x][y]=='.'
				} else {
					ok=false
					break
				}
			}
			if ok {
				cnt++
			}
		}
	}
	println(cnt)
}