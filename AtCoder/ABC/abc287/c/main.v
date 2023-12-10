import os { input }
import math as ma
import arrays as ar
import strings as str
import regex as re
import rand
//import datatypes as dt

pub fn main() {
	n,m:=pl(lni())
	mut g:=new_gr(n,true)
	mut uf:=new_uf(n)
	for _ in 0..m {
		u,v:=pl(lni())
		uf.unite(u-1,v-1)
		g.add(u,v,1)
	}
	mut cnt:=[]int{len:n+1}
	for i in 0..n {
		cnt[g.g[i].len]++
	}
	yes(cnt[3..n+1].all(it==0) && cnt[1]==2 && uf.size(0)==n)
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
fn lni() []int { return si().split(' ').map(it.int()) }
fn ldi() []f64 { return si().split(' ').map(it.f64()) }
fn lbi() []i64 { return si().split(' ').map(it.i64()) }
fn pl[T](ls []T) (T,T) { return ls[0],ls[1] }
fn tl[T](ls []T) (T,T,T) { return ls[0],ls[1],ls[2] }
fn ql[T](ls []T) (T,T,T,T) { return ls[0],ls[1],ls[2],ls[3] }
fn aro[T](a []T) string { return a.map(it.str()).join(' ') }
fn flush[T](arg T) { println(arg) os.flush() }
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
fn cas(s string) int { return s[0] }
fn sygcd(a ...i64) i64 { mut g:=i64(0) for el in a { g=ma.gcd(g,el) } return g }
fn sylcm(a ...i64) i64 { mut l:=i64(1) for el in a { l=ma.lcm(l,el) } return l }
fn symin(a ...i64) i64 { mut res:=ma.maxof[i64]() for el in a { res=ma.min(res,el) } return res }
fn symax(a ...i64) i64 { mut res:=ma.minof[i64]() for el in a { res=ma.max(res,el) } return res }
fn iota(n int, dlt i64) []i64 { return []i64{len: n, init: index+dlt} }
fn mod(n i64, m int) i64 { return (n+m)%m }
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
struct UnionFind {
mut:
	par []int
}
fn new_uf(n int) UnionFind {
	return UnionFind{
		par: []int{len:n,init:-1}
	}
}
fn (mut uf UnionFind) root(i int) int { 
	if uf.par[i]<0{ return i }
	uf.par[i]=uf.root(uf.par[i])
	return uf.par[i]
}
fn (mut uf UnionFind) same(i int, j int) bool { return uf.root(i)==uf.root(j) }
fn (mut uf UnionFind) size(i int) int { return -uf.par[uf.root(i)] }
fn (mut uf UnionFind) unite(i int, j int) bool {
	a:=uf.root(i)
	b:=uf.root(j)
	if a==b { return false }
	if uf.par[a]>uf.par[b] { uf.par[a],uf.par[b]=uf.par[b],uf.par[a] }
	uf.par[a]+=uf.par[b]
	uf.par[b]=a
	return true
}
struct Graph {
	undirected bool
mut:
	g [][]i64
}
fn new_gr(n int, dir bool) Graph{
	return Graph{
		g: [][]i64{len:n}
		undirected: dir
	}
}
fn (mut G Graph) add(a i64, b i64, indexed int) {
	x:=a-indexed
	y:=b-indexed
	G.g[x]<<y
	if G.undirected{ G.g[y]<<x }
}
fn (mut G Graph) in_g(m int, indexed int) {
	for _ in 0..m {
		l:=lbi()
		G.add(l[0],l[1],indexed)
	}
}