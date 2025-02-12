import math.fractions { fraction }

fn main() {
	mut pat := [][]int{}
	for a in 10..100 {
		for b in a+1..100 {
			for c in 1..10 {
				for d in c+1..10 {
					if fraction(a, b) == fraction(c, d) {
						x, y := a.str(), b.str()
						if x[1] == y[0] && ctoi(x[0]) == c && ctoi(y[1]) == d {
							pat << [a, b, c, d]
						}
					}
				}
			}
		}
	}
	assert pat.len == 4
	eprintln(pat)
	mut z := fraction(1, 1)
	for e in pat {
		z *= fraction(e[2], e[3])
	}
	println(z)
}

fn ctoi(c u8) int { return c - '0'[0] }