import arrays{sum}
fn main() {
	mut cnt:=0
	for i in 1..1000001 {
		if sum(i.str().split('').map(it.int()))!%7==0 {
			cnt++
		}
	}
	println(cnt)
}