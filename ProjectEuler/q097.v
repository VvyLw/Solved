import math.big { integer_from_u32, integer_from_u64 }

fn main() {
	mod := integer_from_u64(u64(1e10))
	// eprintln(mod)
	mut n := integer_from_u32(2).mod_pow(7830457, mod)
	n *= integer_from_u32(28433)
	n = n % mod
	n += integer_from_u32(1)
	println(n)
}