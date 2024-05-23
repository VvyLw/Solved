import arrays{rotate_right}
fn main() {
	n:=1000000
	p:=p_table(n)
	q:=p.table()
	// dump(p)
	mut cnt:=0
	for e in p.get() {
		mut t:=e.str().bytes()
		mut ok:=true
		for _ in 0..t.len {
			ok=ok && q[t.bytestr().int()]
			rotate_right(mut t,1)
		}
		if ok {
			cnt++
		}
	}
	println(cnt)
}

pub struct SoE {
mut:
	siege []bool
}
fn (pt SoE) str() string { return '${pt.get()}' }
pub fn p_table(n int) SoE {
	mut tmp:=[]bool{len:n+1,init:true}
	tmp[0]=false
	tmp[1]=false
	for i in 2..n+1 {
		if !tmp[i] { continue }
		for j:=i64(i)*i; j<=n; j+=i { tmp[j]=false }
	}
	return SoE{ siege: tmp }
}
pub fn (pt SoE) table() []bool { return pt.siege }
pub fn (pt SoE) get() []int {
	mut res:=[]int{}
	for i in 2..pt.siege.len {
		if pt.siege[i] { res<<i }
	}
	return res
}