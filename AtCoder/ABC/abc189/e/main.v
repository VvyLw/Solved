import os { input }
import math as ma
import math.big
import arrays as ar
import strings as str
import regex as re
import rand
import time
import datatypes as dt { Set, Queue, Stack, DoublyLinkedList, MinHeap }

pub fn solve()! {
	
}

const (
	mod998=998244353
	mod107=1000000007
	inf=1<<30
	linf=i64(u64(1)<<61)
	dx=[0,0,0,-1,1,-1,-1,1,1]
	dy=[0,-1,1,0,0,-1,1,-1,1]
)
type F1[T]=fn(T)bool
type F2[T]=fn(T,T)bool
fn si() string { return input('') }
fn ni() int { return si().int() }
fn di() f64 { return si().f64() }
fn bi() i64 { return si().i64() }
fn li() []string { return si().split('') }
fn lsi() []string { return si().split(' ') }
fn lni() []int { return lsi().map(it.int()) }
fn ldi() []f64 { return lsi().map(it.f64()) }
fn lbi() []i64 { return lsi().map(it.i64()) }
fn pl[T](ls []T) (T,T) { return ls[0],ls[1] }
fn tl[T](ls []T) (T,T,T) { return ls[0],ls[1],ls[2] }
fn ql[T](ls []T) (T,T,T,T) { return ls[0],ls[1],ls[2],ls[3] }
fn aro[T](a []T) string { return a.map(it.str()).join(' ') }
fn flush[T](arg T) { println(arg) os.flush() }
fn fin[T](arg T) { println(arg) exit(0) }
fn dbg[T](arg T) { eprintln('-----------${arg}-----------') }
fn yn(ok bool, yes string, no string) { println(if ok{yes} else{no}) }
fn yes(ok bool) { yn(ok, "Yes", "No") }
fn no(ok bool) { yes(!ok) }
fn chmin[T, U](mut a T, b U) bool { jdg:=a>b a=ma.min(a,b) return jdg }
fn chmax[T, U](mut a T, b U) bool { jdg:=a<b a=ma.max(a,b) return jdg }
fn toc(n i64) string { return u8(n).ascii_str() }
fn cas(s string) int { return s[0] }
fn sygcd(a []i64) i64 { mut g:=i64(0) for el in a { g=ma.gcd(g,el) } return g }
fn sylcm(a []i64) i64 { mut l:=i64(1) for el in a { l=ma.lcm(l,el) } return l }
fn mod(n i64, m int) i64 { return (n+m)%m }
fn large(n i64) big.Integer { return big.integer_from_i64(n) }
fn stol(s string) !big.Integer { return big.integer_from_string(s)! }
fn iota(n int, dlt i64) []i64 { return []i64{len: n, init: index+dlt} }
fn unq[T](a []T) []T {
	mut res := []T{cap: a.len / 10}
	mut j := -1
	if a.len > 0 {
		j = 0
		res << a[0]
	}
	for idx, e in a {
		if a[j] == e {
			continue
		}
		j = idx
		res << e
	}
	return res
}
fn bs[T](a []T, x T) !int { return ar.binary_search(a,x)! }
fn a_find[T](a []T, filt F1[T]) ?T { return ar.find_first(a,filt) }
fn a_filter[T](a []T, filt F2[T]) []T { return ar.filter_indexed(a,filt) }
fn len(s string) int { return s.split('').len }
fn to_ten(s string, base int) !i64 { return s.parse_int(base,64)! }
fn repstr(s string, n int) string { return str.repeat_string(s,n) }
fn rgxmt(s string, pat string) !bool { r:=re.regex_opt(pat)! return r.matches_string(s) }
fn rext(inf i64, sup i64) !i64 { return rand.i64_in_range(inf,sup)! }
struct Pair[T,U] {
	first T
	second U
}
fn (p Pair[T,U]) str() string { return '${p.first} ${p.second}' }
fn mp[T,U](p T, q U) Pair[T,U] {
	return Pair[T,U] {
		first: p
		second: q
	}
}
pub fn main() {
	mut tm:=time.StopWatch{}
	tm.start()
	mut t:=1
	//t=ni()
	for t-->0 { solve()! }
	tm.stop()
	eprintln(tm.elapsed())
}