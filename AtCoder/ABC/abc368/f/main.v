import os { input }
import arrays { fold, sum }

fn main() {
	_ := input('')
	a := input('').split(' ').map(it.int())
	mut b := []int{}
	for e in a {
		b << sum(prmfct(e).values())!
	}
	println(if fold(b, 0, fn (acc int, e int) int {
		return acc ^ e
	}) != 0 { 'Anna' } else { 'Bruno' })
}

fn prmfct(n i64) map[i64]int {
	mut res := map[i64]int{}
	mut x := n
	for i := 2; i * i <= x; i++ {
		if x % i != 0 {
			continue
		}
		for x % i == 0 {
			res[i]++
			x /= i
		}
	}
	if x != 1 {
		res[x]++
	}
	return res
}
