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
	n:=ni()
	mut a:=[]Pair[int,int]{len:n}
	for i in 0..n {
		a[i]=mp(i+1,li().filter(it=='o').len)
	}
	a.sort_with_compare(fn(a &Pair[int,int], b &Pair[int,int]) int {
		if a.second==b.second { return if a.first<b.first{-1} else if a.first>b.first{1} else{0}}
		return if a.second>b.second{-1} else{1}
	})
	println(aro(first[int,int](a)))
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
fn t2[T](ls []T) (T,T) { return ls[0],ls[1] }
fn t3[T](ls []T) (T,T,T) { return ls[0],ls[1],ls[2] }
fn t4[T](ls []T) (T,T,T,T) { return ls[0],ls[1],ls[2],ls[3] }
fn t5[T](ls []T) (T,T,T,T,T) { return ls[0],ls[1],ls[2],ls[3],ls[4] }
fn t6[T](ls []T) (T,T,T,T,T,T) { return ls[0],ls[1],ls[2],ls[3],ls[4],ls[5] }
fn aro[T](a []T) string { return a.map(it.str()).join(' ') }
fn flush[T](arg T) { println(arg) os.flush() }
fn fin[T](arg T) { println(arg) exit(0) }
fn dbg[T](arg T) { eprintln('-----------${arg}-----------') }
fn yn(ok bool, yes string, no string) { println(if ok{yes} else{no}) }
fn yes(ok bool) { yn(ok, "Yes", "No") }
fn no(ok bool) { yes(!ok) }
fn toc(n i64) string { return u8(n).ascii_str() }
fn cas(s string) int { return s[0] }
fn chmin[T, U](mut a T, b U) bool { jdg:=a>b a=ma.min(a,b) return jdg }
fn chmax[T, U](mut a T, b U) bool { jdg:=a<b a=ma.max(a,b) return jdg }
fn symin(a ...i64) i64 { mut res:=ma.maxof[i64]() for el in a { res=ma.min(res,el) } return res }
fn symax(a ...i64) i64 { mut res:=ma.minof[i64]() for el in a { res=ma.max(res,el) } return res }
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
fn scope(a i64, x i64, b i64) bool { return a<=x && x<=b }
fn to_ten(s string, base int) !i64 { return s.parse_int(base,64)! }
fn repstr(s string, n int) string { return str.repeat_string(s,n) }
fn rgxmt(s string, pat string) !bool { r:=re.regex_opt(pat)! return r.matches_string(s) }
fn rext(inf i64, sup i64) !i64 { return rand.i64_in_range(inf,sup)! }
fn div(n i64) []i64 {
	mut res:=[]i64{}
	for i:=1; i*i<=n; i++ {
		if n%i==0 {
			res<<i
			if i*i!=n { res<<n/i }
		}
	}
	res.sort()
	return res
}
fn is_int(n f64) bool { return n==ma.floor(n) }
fn is_sqr(n i64) bool { return is_int(ma.sqrt(n)) }
fn is_prime(n i64) bool {
	if n==1 { return false }
	for i:=2; i*i<=n; i++ {
		if n%i==0 { return false }
	}
	return true
}
fn prmfct(n i64) map[i64]int {
	mut res:=map[i64]int{}
	for i:=2; i*i<=n; i++ {
		if n%i!=0 { continue }
		mut x:=n
		for x%i==0 {
			res[i]++
			x/=i
		}
	}
	if n!=1 { res[n]++ }
	return res
}
struct SoE {
mut:
	siege []bool
}
fn (pt SoE) str() string { return '${pt.siege}' }
fn p_table(n int) SoE {
	mut tmp:=[]bool{len:n+1,init:true}
	tmp[0]=false
	tmp[1]=false
	for i in 2..n+1 {
		if !tmp[i] { continue }
		for j:=i*i; j<=n; j+=i { tmp[j]=false }
	}
	return SoE{ siege: tmp }
}
fn (pt SoE) get() []int {
	mut res:=[]int{}
	for i in 2..pt.siege.len {
		if pt.siege[i] { res<<i }
	}
	return res
}
struct SPF {
mut:
	spf []int
}
fn (pf SPF) str() string { return '${pf.spf}' }
fn p_fact(n int) SPF {
	mut tmp:=[]int{len:n+1,init:index}
	for i:=2; i*i<=n; i++ {
		if tmp[i]==i {
			for j:=i*i; j<=n; j+=i {
				if tmp[j]==j { tmp[j]=i }
			}
		}
	}
	return SPF{ spf: tmp }
}
fn (pf SPF) get(n int) map[int]int {
	mut res:=map[int]int{}
	mut x:=n
	for x!=1 {
		res[pf.spf[x]]++
		x/=pf.spf[x]
	}
	return res
}
struct Asum {
mut:
	acc []i64
}
fn asum(a []i64) Asum {
	mut s:=[i64(0)]
	for i,el in a { s<<s[i]+el }
	return Asum{ acc: s }
}
fn (a Asum) str() string { return '${a.acc}' }
fn (a Asum) query(l int, r int) i64 { return a.acc[r]-a.acc[l] }
fn perm(n i64, r i64) i64 {
	mut tmp:=n
	mut res:=i64(1)
	for tmp>n-r { res*=tmp-- }
	return res
}
fn binom(n i64, r i64) i64 {
	if r<0 || n<r { return 0 }
	mut tmp:=n
	mut res:=i64(1)
	for i in 1..r+1 {
		res*=tmp--
		res/=i
	}
	return res
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
fn (p Pair[T,T])+(q Pair[T,T]) Pair[T,T] { return Pair[T,T]{p.first+p.second,q.first+q.second} }
fn (p Pair[T,T])-(q Pair[T,T]) Pair[T,T] { return Pair[T,T]{p.first-p.second,q.first-q.second} }
fn (p Pair[T,T])*(q Pair[T,T]) Pair[T,T] { return Pair[T,T]{p.first*p.second,q.first*q.second} }
fn (p Pair[T,T])/(q Pair[T,T]) Pair[T,T] { return Pair[T,T]{p.first/p.second,q.first/q.second} }
fn (p Pair[T,U])==(q Pair[T,U]) bool { return  p.first==q.first && p.second==q.second }
fn (p Pair[T,U])<(q Pair[T,U]) bool { if p.first==q.first{ return p.second<q.second } return p.first<q.first }
fn (p Pair[T,T]) rotate(ang int) Pair[f64, f64] {
	assert scope(0,ang,359)
	rad:=ma.radians(ang)
	return Pair[f64, f64]{p.first*ma.cos(rad)-p.second*ma.sin(rad), p.first*ma.sin(rad)+p.second*ma.cos(rad)}
}
fn (p Pair[T,T]) rtt90() Pair[T,T] { return Pair[T,T]{-p.second,p.first} }
fn (p Pair[T,T]) dot(q Pair[T,T]) T { return p.first*q.first+p.second*q.second }
fn (p Pair[T,T]) cross(q Pair[T,T]) T { return p.dot(p.rtt90,q) }
fn (p Pair[T,T]) square() T { return p.dot(p) }
fn (p Pair[T,T]) grad() f64 { assert p.first!=0 return f64(p.second)/p.first }
fn (p Pair[T,T]) abs() T { return ma.hypot(p.first,p.second) }
fn (p Pair[T,T]) lcm() T { return ma.lcm(p.first,p.second) }
fn (p Pair[T,T]) gcd() T { return ma.gcd(p.first,p.second) }
fn (p Pair[T,T]) extgcd() Pair[T,T] {
	mut x:=1 mut y:=0 mut t1:=0 mut t2:=0 mut t3:=1
	mut a:=p.first mut b:=p.second
	for b!=0 {
		t1=a/b a-=t1*b
		a,b=b,a
		x-=t1*t2
		x,t2=t2,x
		y-=t1*t3
		y,t3=t3,y
	}
	return Pair[T,T]{x,y}
}
fn (p Pair[T,T]) normalize() Pair[T,T] {
	if p==Pair[T,T]{} { return p }
	p/=p.gcd()
	if p<Pair[T,T]{} { p=-p }
	return p
}
fn (p Pair[T,U]) swap() Pair[U,T] { return Pair[U,T]{p.second,p.first} }
fn swap[T,U](p []Pair[T,U]) []Pair[U,T] {
	mut ret:=[]Pair[U,T]{}
	for el in p { ret<<mp(el.first,el.second) }
	return ret
}
fn first[T,U](p []Pair[T,U]) []T {
	mut ret:=[]T{}
	for el in p { ret<<el.first }
	return ret
}
fn second[T,U](p []Pair[T,U]) []U {
	mut ret:=[]U{}
	for el in p { ret<<el.second }
	return ret
}