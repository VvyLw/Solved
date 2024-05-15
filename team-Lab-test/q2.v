fn main() {
	mut cnt,mut now:=1,0
	for i:=800; i>0; i-- {
		if now+i>5000 {
			cnt++
			now=0
		}
		now+=i
	}
	println(cnt)
}