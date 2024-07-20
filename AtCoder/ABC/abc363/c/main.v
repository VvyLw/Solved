import os { input }

fn main() {
	nk := input('').split(' ').map(it.int())
	n, k := nk[0], nk[1]
	mut s := input('').split('')
	s.sort()
	mut cnt := 0
	for {
		if []string{len: n - k + 1, init: s[index..index + k].join('')}.all(!is_pld(it)) {
			cnt++
		}
		if !next_permutation(mut s) {
			break
		}
	}
	println(cnt)
}

fn is_pld(s string) bool {
	return s == s.reverse()
}

pub fn next_permutation[T](mut a []T) bool {
	for i := a.len - 1; i > 0; i-- {
		if a[i - 1] < a[i] {
			j := find(a[i - 1], a, i, a.len - 1)
			a[i - 1], a[j] = a[j], a[i - 1]
			a[i..a.len].sort(a < b)
			return true
		}
	}
	return false
}

fn find[T](dest T, a []T, s int, e int) int {
	if s == e {
		return s
	}
	m := (s + e + 1) / 2
	return if a[m] <= dest { find(dest, a, s, m - 1) } else { find(dest, a, m, e) }
}
