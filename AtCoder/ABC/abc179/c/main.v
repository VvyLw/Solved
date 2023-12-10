import os { input }
import math as ma
import arrays as ar
import strings as str
import regex as re
//import datatypes as dt
const (
	mod998=998244353
	mod107=1000000007
	inf=1<<30
	linf=1<<61
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
fn lni() []int { return si().split(' ').map(it.int()) }
fn ldi() []f64 { return si().split(' ').map(it.f64()) }
fn lbi() []i64 { return si().split(' ').map(it.i64()) }
fn aro[T](a []T) string { return a.map(it.str()).join(' ') }
fn dbg[T](args ...T) {
	eprintln('---------------------')
	for id, el in args { eprintln('arg${id}: ${el}') }
	eprintln('---------------------')
}
fn yes(ok bool) { println(if ok {'Yes'} else {'No'}) }
fn no(ok bool) { yes(!ok) }
fn chmin[T, U](mut a T, b U) bool { jdg:=a>b a=ma.min(a,b) return jdg }
fn chmax[T, U](mut a T, b U) bool { jdg:=a<b a=ma.max(a,b) return jdg }
fn toc(n i64) string { return u8(n).ascii_str() }
fn sygcd(a ...i64) i64 { mut g:=i64(0) for el in a { g=ma.gcd(g,el) } return g }
fn sylcm(a ...i64) i64 { mut l:=i64(1) for el in a { l=ma.lcm(l,el) } return l }
fn symin(a ...i64) i64 { mut res:=ma.maxof[i64]() for el in a { res=ma.min(res,el) } return res }
fn symax(a ...i64) i64 { mut res:=ma.minof[i64]() for el in a { res=ma.max(res,el) } return res }
fn iota(n int, dlt i64) []i64 { return []i64{len: n, init: index+dlt} }
fn mod(n int, m int) int { return (n+m)%m }
fn bs[T](a []T, x T) !int { return ar.binary_search(a,x)! }
fn a_find[T](a []T, filt F1[T]) ?T { return ar.find_first(a,filt) }
fn a_filter[T](a []T, filt F2[T]) []T { return ar.filter_indexed(a,filt) }
fn repstr(s string, n int) string { return str.repeat_string(s,n) }
fn rgxmt(s string, pat string) !bool { r:=re.regex_opt(pat)! return r.matches_string(s) }
fn graph(n int) [][]int { return [][]int{len:n} }
struct Pair[T,U] {
	first T
	second U
}
pub fn main() {
	n:=ni()
	mut cnt:=0
	for i in 1..n {
		cnt+=(n-1)/i
	}
	println(cnt)
}