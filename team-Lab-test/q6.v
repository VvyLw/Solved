fn main() {
	s:="AEKORST".split('')
	mut cnt:=0
	for a in s {
		for b in s {
			for c in s {
				for d in s {
					for e in s {
						if (a+b+c+d+e).contains("OK") {
							cnt++
						}
					}
				}
			}
		}
	}
	println(cnt)
}