fn main() {
	for x in 10000 .. 100000000 {
		mut cnt := []int{len: 10}
		for c in x.str() {
			cnt[c - '0'[0]]++
		}
		mut ok := true
		for i in 2 .. 7 {
			mut d := []int{len: 10}
			for c in (x * i).str() {
				d[c - '0'[0]]++
			}
			ok &&= cnt == d
		}
		if ok {
			println(x)
			for i in 2 .. 7 {
				eprintln(x * i)
			}
			break
		}
	}
}