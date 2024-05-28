import os{input}
import math as ma{min,max,floor,sqrt,radians,cos,sin,hypot}
import math.big{integer_from_i64,integer_from_string,integer_from_u32,integer_from_u64}
import math.bits{leading_zeros_32,trailing_zeros_64}
import arrays as ar
import regex as re
import strings{new_builder}
import rand
import time{StopWatch}
import datatypes{Queue,Stack}

pub fn solve()! {
	p:=p_table(17).get()
	mut a:=iota(10,0)
	mut s:=i64(0)
	for {
		d:=a.map(it.str()).join('')
		mut ok:=true
		for i,e in p {
			ok=ok && d[i+1..i+4].int()%e==0
		}
		if ok {
			s+=d.i64()
		}
		if !next_permutation(mut a) {
			break
		}
	}
	println(s)
}

pub const (
	multi=false
	mod998=998244353
	mod107=1000000007
	inf=1<<30
	linf=i64(u64(1)<<61)-1
	dx=[0,0,0,-1,1,-1,-1,1,1]
	dy=[0,-1,1,0,0,-1,1,-1,1]
)
type F1[T]=fn(T)bool
type F2[T]=fn(T,T)bool
pub fn si() string { return input('') }
pub fn ni() int { return si().int() }
pub fn di() f64 { return si().f64() }
pub fn bi() i64 { return si().i64() }
pub fn li() []string { return sa(si()) }
pub fn lsi() []string { return si().split(' ') }
pub fn lni() []int { return lsi().map(it.int()) }
pub fn ldi() []f64 { return lsi().map(it.f64()) }
pub fn lbi() []i64 { return lsi().map(it.i64()) }
pub fn t2[T](ls []T) (T,T) { return ls[0],ls[1] }
pub fn t3[T](ls []T) (T,T,T) { return ls[0],ls[1],ls[2] }
pub fn t4[T](ls []T) (T,T,T,T) { return ls[0],ls[1],ls[2],ls[3] }
pub fn t5[T](ls []T) (T,T,T,T,T) { return ls[0],ls[1],ls[2],ls[3],ls[4] }
pub fn t6[T](ls []T) (T,T,T,T,T,T) { return ls[0],ls[1],ls[2],ls[3],ls[4],ls[5] }
pub fn t7[T](ls []T) (T,T,T,T,T,T,T) { return ls[0],ls[1],ls[2],ls[3],ls[4],ls[5],ls[6] }
pub fn aro[T](a []T) string { return a.map(it.str()).join(' ') }
pub fn flush[T](arg T) { println(arg) os.flush() }
pub fn yn(ok bool, yes string, no string) string { return if ok{yes} else{no} }
pub fn yes(ok bool) string { return yn(ok, "Yes", "No") }
pub fn no(ok bool) string { return yes(!ok) }
pub fn toc(n i64) string { return u8(n).ascii_str() }
pub fn ord(s string) int { return s[0] }
pub fn sa(s string) []string { return s.split('') }
pub fn sas(s []string) string { return s.join('') }
pub fn chmin[T](mut a T, b T) bool { jdg:=a>b a=min(a,b) return jdg }
pub fn chmax[T](mut a T, b T) bool { jdg:=a<b a=max(a,b) return jdg }
pub fn symin(a ...i64) i64 { mut res:=linf for el in a { res=min(res,el) } return res }
pub fn symax(a ...i64) i64 { mut res:=-linf for el in a { res=max(res,el) } return res }
pub fn sygcd(a []i64) i64 { mut g:=i64(0) for el in a { g=ma.gcd(g,el) } return g }
pub fn sylcm(a []i64) i64 { mut l:=i64(1) for el in a { l=ma.lcm(l,el) } return l }
pub fn mod(n i64, m i64) i64 { k:=n%m return if k<0 { k+m } else { k } }
pub fn large(n i64) big.Integer { return big.integer_from_i64(n) }
pub fn stol(s string) !big.Integer { return big.integer_from_string(s)! }
pub fn iota(n int, dlt int) []int { return []int{len: n, init: index+dlt} }
pub fn unq[T](a []T) []T {
	mut res:=[]T{cap:a.len/10}
	mut j:=-1
	if a.len>0 {
		j=0
		res<<a[0]
	}
	for idx,e in a {
		if a[j]==e {
			continue
		}
		j=idx
		res<<e
	}
	return res
}
pub fn bs[T](a []T, b T) bool {
	_:=ar.binary_search(a,b) or { return false }
	return true
}
pub fn lb[T](a []T, b T) int {
	mut ok,mut ng:=a.len,-1
	for math.abs(ok-ng)>1 {
		mid:=(ok+ng)/2
		if a[mid]>=b {
			ok=mid
		} else {
			ng=mid
		}
	}
	return ok
}
pub fn ub[T](a []T, b T) int {
	mut ok,mut ng:=a.len,-1
	for math.abs(ok-ng)>1 {
		mid:=(ok+ng)/2
		if a[mid]>b {
			ok=mid
		} else {
			ng=mid
		}
	}
	return ok
}
pub fn scope(a i64, x i64, b i64) bool { return a<=x && x<=b }
pub fn to_ten(s string, base int) !i64 { return s.parse_int(base,64)! }
pub fn rgxmt(s string, pat string) !bool { r:=re.regex_opt(pat)! return r.matches_string(s) }
pub fn rext(inf i64, sup i64) !i64 { return rand.i64_in_range(inf,sup)! }

pub fn main() {
	mut tm:=StopWatch{}
	tm.start()
	t:=if multi { ni() } else { 1 }
	for _ in 0..t { solve()! }
	tm.stop()
	$if debug {
		eprintln(tm.elapsed())
	}
}

pub fn is_int(n f64) bool { return n==floor(n) }
pub fn is_sqr(n i64) bool { return is_int(sqrt(n)) }
pub fn is_prime(n i64) bool {
	if n==1 {
		return false
	}
	if n<=3 {
		return true
	}
	if n%2==0 || n%3==0 {
		return false
	}
	for i:=5; i*i<=n; i+=6 {
		if n%i==0 || n%(i+2)==0 {
			return false
		}
	}
	return true
}
pub fn div(n i64) []i64 {
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
pub fn prmfct(n i64) map[i64]int {
	mut res:=map[i64]int{}
	mut x:=n
	for i:=2; i*i<=x; i++ {
		if x%i!=0 { continue }
		for x%i==0 {
			res[i]++
			x/=i
		}
	}
	if x!=1 { res[x]++ }
	return res
}
pub fn perm(n i64, r i64) i64 {
	mut tmp:=n
	mut res:=i64(1)
	for tmp>n-r { res*=tmp-- }
	return res
}
pub fn binom(n i64, r i64) i64 {
	if r<0 || n<r { return 0 }
	mut tmp:=n
	mut res:=i64(1)
	for i in 1..r+1 {
		res*=tmp--
		res/=i
	}
	return res
}
pub fn radix_convert(n i64, radix u8) []u8 {
	if n==0 {
		return [u8(0)]
	}
	mut m:=n
	mut res:=[]u8{}
	for m>0 {
		res<<u8(m%radix)
		m/=radix
	}
	return res.reverse()
}

pub struct Asum {
mut:
	acc []i64
}
pub fn psum[T](a []T) Asum {
	mut s:=[i64(0)]
	for i,el in a { s<<s[i]+el }
	return Asum{ acc: s }
}
fn (a Asum) str() string { return '${a.acc}' }
pub fn (a Asum) get() []i64 { return a.acc }
pub fn (a Asum) sum(l int, r int) i64 { return a.acc[r]-a.acc[l] }

pub struct SPF {
mut:
	spf []int
}
fn (pf SPF) str() string { return '${pf.spf}' }
pub fn p_fact(n int) SPF {
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
pub fn (pf SPF) get(n int) map[int]int {
	mut res:=map[int]int{}
	mut x:=n
	for x!=1 {
		res[pf.spf[x]]++
		x/=pf.spf[x]
	}
	return res
}

pub struct SoE {
mut:
	siege []bool
}
fn (pt SoE) str() string { return '${pt.siege}' }
pub fn p_table(n int) SoE {
	mut tmp:=[]bool{len:n+1,init:true}
	tmp[0]=false
	tmp[1]=false
	for i in 2..n+1 {
		if !tmp[i] { continue }
		for j:=i*i; j<=n; j+=i { tmp[j]=false }
	}
	return SoE{ siege: tmp }
}
pub fn (pt SoE) get() []int {
	mut res:=[]int{}
	for i in 2..pt.siege.len {
		if pt.siege[i] { res<<i }
	}
	return res
}

pub fn next_permutation[T](mut a []T) bool {
	for i:=a.len-1; i>0; i-- {
		if a[i-1]<a[i] {
			j:=find(a[i-1],a,i,a.len-1)
			a[i-1],a[j]=a[j],a[i-1]
			a[i..a.len].sort(a<b)
			return true
		}
	}
	return false
}
pub fn prev_permutation[T](mut a []T) bool {
	for i:=a.len-1; i>0; i-- {
		if a[i-1]>a[i] {
			j:=find_rev(a[i-1],a,i,a.len-1)
			a[i-1],a[j]=a[j],a[i-1]
			a[i..a.len].sort(a>b)
			return true
		}
	}
	return false
}
fn find[T](dest T, a []T, s int, e int) int {
	if s==e {
		return s
	}
	m:=(s+e+1)/2
	return if a[m]<=dest { find(dest,a,s,m-1) } else { find(dest,a,m,e) }
}
fn find_rev[T](dest T, a []T, s int, e int) int {
	if s==e {
		return s
	}
	m:=(s+e+1)/2
	return if a[m]>dest { find_rev(dest,a,s,m-1) } else { find_rev(dest,a,m,e) }
}

pub struct Pair[T,U] {
	first T
	second U
}
fn (p Pair[T,U]) str() string { return '(${p.first}, ${p.second})' }
pub fn mp[T,U](p T, q U) Pair[T,U] {
	return Pair[T,U] {
		first: p
		second: q
	}
}
fn (p Pair[T,U])+(q Pair[T,U]) Pair[T,U] { return Pair[T,U]{p.first+q.first,p.second+q.second} }
fn (p Pair[T,U])-(q Pair[T,U]) Pair[T,U] { return Pair[T,U]{p.first-q.first,p.second-q.second} }
fn (p Pair[T,U])*(q Pair[T,U]) Pair[T,U] { return Pair[T,U]{p.first*q.first,p.second*q.second} }
fn (p Pair[T,U])/(q Pair[T,U]) Pair[T,U] { return Pair[T,U]{p.first/q.first,p.second/q.second} }
fn (p Pair[T,U])==(q Pair[T,U]) bool { return p.first==q.first && p.second==q.second }
fn (p Pair[T,U])<(q Pair[T,U]) bool { if p.first==q.first{ return p.second<q.second } return p.first<q.first }
pub fn (p Pair[T,T]) rotate(ang int) Pair[f64, f64] {
	assert 0<=ang && ang<360
	rad:=radians(ang)
	return Pair[f64, f64]{p.first*cos(rad)-p.second*sin(rad), p.first*sin(rad)+p.second*cos(rad)}
}
pub fn (p Pair[T,T]) rtt90() Pair[T,T] { return mp(-p.second,p.first) }
pub fn (p Pair[T,T]) dot(q Pair[T,T]) T { return p.first*q.first+p.second*q.second }
pub fn (p Pair[T,T]) square() T { return p.dot(p) }
pub fn (p Pair[T,T]) grad() f64 { assert p.first!=0 return f64(p.second)/p.first }
pub fn (p Pair[T,T]) abs() f64 { return hypot(p.first,p.second) }
pub fn (p Pair[T,T]) lcm() i64 { return ma.lcm(p.first,p.second) }
pub fn (p Pair[T,T]) gcd() i64 { return ma.gcd(p.first,p.second) }
pub fn (p Pair[T,U]) swap() Pair[U,T] { return Pair[U,T]{p.second,p.first} }

pub struct Graph {
	undirected bool
	idx int
mut:
	g [][]int
}
fn (gr Graph) str() string {
	mut sb:=new_builder(0)
	n:=gr.g.len
	for i in 0..n {
		sb.write_string("$i: ${gr.g[i]}")
		if i+1<n {
			sb.write_string("\n")
		}
	}
	return sb.str()
}
pub fn graph(n int, idx int, undirected bool) Graph {
	return Graph {
		g: [][]int{len:n}
		idx: idx
		undirected: undirected
	}
}
pub fn (mut gr Graph) add(a int, b int) {
	x:=a-gr.idx
	y:=b-gr.idx
	gr.g[x]<<y
	if gr.undirected { gr.g[y]<<x }
}
pub fn (mut gr Graph) ing(m int) {
	for _ in 0..m {
		l:=input('').split(' ').map(it.int())
		gr.add(l[0],l[1])
	}
}
pub fn (gr Graph) all_dist(v int) ![]int {
	mut d:=[]int{len:gr.g.len,init:-1}
	mut q:=Queue[int]{}
	d[v]=0
	q.push(v)
	for !q.is_empty() {
		tmp:=q.pop()!
		for el in gr.g[tmp] {
			if d[el]!=-1 { continue }
			d[el]=d[tmp]+1
			q.push(el)
		}
	}
	return d
}
pub fn (gr Graph) dist(a int, b int) !int { return gr.all_dist(a)![b] }
pub fn (gr Graph) t_sort() ![]int {
	n:=gr.g.len
	mut deg:=[]int{len:n}
	for i in 0..n {
		for ed in gr.g[i] {
			deg[ed]++
		}
	}
	mut sk:=Stack[int]{}
	for i in 0..n {
		if deg[i]==0 {
			sk.push(i)
		}
	}
	mut ord:=[]int{}
	for !sk.is_empty() {
		tmp:=sk.pop()!
		ord<<tmp
		for ed in gr.g[tmp] {
			deg[ed]--
			if deg[ed]==0 {
				sk.push(ed)
			}
		}
	}
	return if ord.len==n {ord} else {[]int{}}
}

pub struct UnionFind {
mut:
	par []int
}
pub fn UnionFind.new(n int) UnionFind {
	return UnionFind{
		par: []int{len:n,init:-1}
	}
}
fn (mut uf UnionFind) str() string { return '${uf.groups()}'}
pub fn (mut uf UnionFind) root(i int) int { 
	if uf.par[i]<0{ return i }
	uf.par[i]=uf.root(uf.par[i])
	return uf.par[i]
}
pub fn (mut uf UnionFind) same(i int, j int) bool { return uf.root(i)==uf.root(j) }
pub fn (mut uf UnionFind) size(i int) int { return -uf.par[uf.root(i)] }
pub fn (mut uf UnionFind) unite(i int, j int) bool {
	a:=uf.root(i)
	b:=uf.root(j)
	if a==b { return false }
	if uf.par[a]>uf.par[b] { uf.par[a],uf.par[b]=uf.par[b],uf.par[a] }
	uf.par[a]+=uf.par[b]
	uf.par[b]=a
	return true
}
pub fn (mut uf UnionFind) groups() [][]int {
	n:=uf.par.len
	mut res:=[][]int{len:n,init:[]int{}}
	for i in 0..n { res[uf.root(i)]<<i }
	return res.filter(it.len>0)
}
pub fn is_bipartite(mut uf UnionFind) bool {
	assert uf.par.len%2==0
	n:=uf.par.len/2
	mut ok:=true
	for i in 0..n {
		ok=ok && !uf.same(i,i+n)
	}
	return ok
}

pub struct WeightedUnionFind {
mut:
	par []int
	weight []i64
}
pub fn WeightedUnionFind.new(n int) WeightedUnionFind {
	return WeightedUnionFind {
		par: []int{len:n,init:-1}
		weight: []i64{len:n}
	}
}
fn (mut uf WeightedUnionFind) str() string { return '${uf.groups()}'}
pub fn (mut uf WeightedUnionFind) root(i int) int {
	if uf.par[i]<0 {
		return i
	}
	r:=uf.root(uf.par[i])
	uf.weight[i]+=uf.weight[uf.par[i]]
	uf.par[i]=r
	return r
}
pub fn (mut uf WeightedUnionFind) get(i int) i64 {
	uf.root(i)
	return uf.weight[i]
}
pub fn (mut uf WeightedUnionFind) unite(i int, j int, wg i64) int {
	mut w:=wg+uf.get(i)-uf.get(j)
	mut x:=uf.root(i)
	mut y:=uf.root(j)
	if x==y {
		return if w==0 {0} else {-1}
	}
	if uf.par[x]>uf.par[y] {
		x,y=y,x
		w=-w
	}
	uf.par[x]+=uf.par[y]
	uf.par[y]=x
	uf.weight[y]=w
	return 1
}
pub fn (mut uf WeightedUnionFind) size(i int) int { return -uf.par[uf.root(i)] }
pub fn (mut uf WeightedUnionFind) groups() [][]int {
	n:=uf.par.len
	mut res:=[][]int{len:n,init:[]int{}}
	for i in 0..n {
		res[uf.root(i)]<<i
	}
	return res.filter(it.len>0)
}

pub struct Deque[T] {
mut:
	len int
	head int
	tail int
	buf []T
}
pub fn Deque.new[T]() Deque[T] {
	return Deque[T] {
		len: 1<<17
		head: 0
		tail: 0
		buf: []T{len:1<<17}
	}
}
pub fn Deque.new_a[T](a []T) Deque[T] {
	mut dq:=Deque.new(a.len)
	for e in a {
		dq.push_back(e)
	}
	return dq
}
fn (dq Deque[T]) str() string { return '${dq.array()}' }
pub fn (dq Deque[T]) array() []T {
	n:=dq.size()
	mut a:=[]T{len:n}
	for i in 0..n {
		a[i]=dq.get(i)
	}
	return a
}
fn (dq Deque[T]) next(i int) int {
	next:=i+1
	return if next==dq.len { 0 } else { next }
}
fn (dq Deque[T]) prev(i int) int {
	prev:=i-1
	return if prev==-1 { dq.len-1 } else { prev }
}
fn (dq Deque[T]) index(i int) int {
	size:=dq.size()
	assert i<size
	id:=dq.head+i
	return if dq.len<=id { id-dq.len } else { id }
}
fn (dq Deque[T]) arraycopy(from_id int, mut a []T, from int, len int) {
	assert from_id+len<=dq.size()
	h:=dq.index(from_id)
	if h+len<dq.len {
		for i in from..len {
			a[i]=dq.buf[i+h]
		}
	} else {
		back:=dq.len-h
		for i in from..back {
			a[i]=dq.buf[i+h]
		}
		for i in from+back..len-back {
			a[i]=dq.buf[i]
		}
	}
}
fn (mut dq Deque[T]) extend() {
	mut tmp:=[]T{len:dq.len*2}
	dq.arraycopy(0,mut tmp,0,dq.size())
	dq.buf=tmp
	dq.len=dq.buf.len
}
pub fn (dq Deque[T]) is_empty() bool { return dq.size()==0 }
pub fn (dq Deque[T]) size() int {
	size:=dq.tail-dq.head
	return if size<0 { size+dq.len } else { size }
}
pub fn (mut dq Deque[T]) push_front(x T) {
	if dq.prev(dq.head)==dq.tail {
		dq.extend()
	}
	dq.head=dq.prev(dq.head)
	dq.buf[dq.head]=x
}
pub fn (mut dq Deque[T]) push_back(x T) {
	if dq.next(dq.tail)==dq.head {
		dq.extend()
	}
	dq.buf[dq.tail]=x
	dq.tail=dq.next(dq.tail)
}
pub fn (mut dq Deque[T]) pop_front() !T {
	if dq.head==dq.tail {
		return error('Deque is empty')
	}
	res:=dq.buf[dq.head]
	dq.head=dq.next(dq.head)
	return res
}
pub fn (mut dq Deque[T]) pop_back() !T {
	if dq.head==dq.tail {
		return error('Deque is empty')
	}
	dq.tail=dq.prev(dq.tail)
	return dq.buf[dq.tail]
}
pub fn (dq Deque[T]) front() T { return dq.get(0) }
pub fn (dq Deque[T]) back() T { return dq.get(dq.len-1) }
pub fn (dq Deque[T]) get(i int) T { return dq.buf[dq.index(i)] }
pub fn (mut dq Deque[T]) set(i int, x T){ dq.buf[dq.index(i)]=x }
pub fn (mut dq Deque[T]) swap(a int, b int) {
	i:=dq.index(a)
	j:=dq.index(b)
	dq.buf[i],dq.buf[j]=dq.buf[j],dq.buf[i]
}
pub fn (mut dq Deque[T]) clear() {
	dq.head=0
	dq.tail=0
}

pub struct FenwickTree {
	n int
mut:
	data []i64
}
pub fn FenwickTree.new(n int) FenwickTree {
	return FenwickTree{
		n: n+2
		data: []i64{len:n+3}
	}
}
pub fn FenwickTree.new_a[T](a []T) FenwickTree {
	mut bit:=FenwickTree.new(a.len)
	for i,e in a {
		bit.add(i,i64(e))
	}
	return bit
}
fn (bit FenwickTree) str() string { return '${bit.array()}' }
fn (bit FenwickTree) array() []i64 {
	mut a:=[]i64{len:bit.n-2}
	for i in 0..bit.n-2 {
		a[i]=bit.sum(i)
	}
	return a
}
pub fn (bit FenwickTree) sum(k int) i64 {
	if k<0 {
		return 0
	}
	mut res:=i64(0)
	for i:=k+1; i>0; i-=i&-i {
		res+=bit.data[i]
	}
	return res
}
pub fn (bit FenwickTree) range_sum(l int, r int) i64 { return bit.sum(r)-bit.sum(l-1)}
pub fn (bit FenwickTree) get(i int) i64 { return bit.sum(i)-bit.sum(i-1) }
pub fn (mut bit FenwickTree) add(k int, x i64) {
	for i:=k+1; i<bit.n; i+=i&-i {
		bit.data[i]+=x
	}
}
pub fn (mut bit FenwickTree) imos(l int, r int, x i64) {
	bit.add(l, x)
	bit.add(r+1,-x)
}
fn lg(n int) int { return 31-leading_zeros_32(u32(n)) }
pub fn (bit FenwickTree) lower_bound(w i64) int {
	if w<=0 {
		return 0
	}
	mut x:=w
	mut i:=0
	for k:=1<<lg(bit.n); k>0; k>>=1 {
		if i+k<=bit.n-1 && bit.data[i+k]<x {
			x-=bit.data[i+k]
			i+=k
		}
	}
	return i
}
pub fn (bit FenwickTree) upper_bound(w i64) int {
	if w<0 {
		return 0
	}
	mut x:=w
	mut i:=0
	for k:=1<<lg(bit.n); k>0; k>>=1 {
		if i+k<=bit.n-1 && bit.data[i+k]<=x {
			x-=bit.data[i+k]
			i+=k
		}
	}
	return i
}
pub fn inv_num[T](a []T) i64 {
	n:=a.len
	mut b:=a.clone()
	b.sort(a<b)
	mut id:=map[T]int{}
	for i in 0..n {
		id[b[i]]=i
	}
	mut fw:=FenwickTree.new(n)
	mut res:=i64(0)
	for i in 0..n {
		res+=i-fw.sum(id[a[i]])
		fw.add(id[a[i]],1)
	}
	return res
}
fn bsf(n u64) u32 { return u32(trailing_zeros_64(n)) }
fn b_gcd(x u64, y u64) u64 {
	mut a,mut b:=ma.abs(x),ma.abs(y)
	if a==0 {
		return b
	}
	if b==0 {
		return a
	}
	shift:=bsf(a|b)
	a>>=bsf(a)
	for {
		b>>=bsf(b)
		if a>b {
			a,b=b,a
		}
		b-=a
		if b<=0 {
			break
		}
	}
	return a<<shift
}
fn f(x u64, st u32, n u64) u64 { return ((integer_from_u64(x)*integer_from_u64(x)+integer_from_u32(st))%integer_from_u64(n)).str().u64() }
fn g(n u64) !u64 {
	if miller_rabin(n)! {
		return n
	}
	if n%2==0 {
		return 2
	}
	mut st:=u32(0)
	for {
		st++
		mut x:=u64(st)
		mut y:=f(u64(x),st,n)
		for {
			p:=b_gcd(y-x+n,n)
			if p==0 || p==n {
				break
			}
			if p!=1 {
				return p
			}
			x,y=f(x,st,n),f(f(y,st,n),st,n)
		}
	}
	return 0
}
pub fn miller_rabin(n u64) !bool {
	if n<=1 {
		return false
	}
	if n==2 {
		return true
	}
	if n%2==0 {
		return false
	}
	mut d:=n-1
	for d%2==0 {
		d/=2
	}
	sample:=[u32(2),3,5,7,11,13,17,19,23,29,31,37]
	for a in sample {
		if n<=a {
			break
		}
		mut t:=d
		mut y:=integer_from_u32(a).big_mod_pow(integer_from_u64(t),integer_from_u64(n))!.str().u64()
		for t!=n-1 && y!=1 && y!=n-1 {
			y=integer_from_u64(y).mod_pow(2,integer_from_u64(n)).str().u64()
			t<<=1
		}
		if y!=n-1 && t%2==0 {
			return false
		}
	}
	return true
}
pub fn pollard_rho(n u64) ![]u64 {
	if n==1 {
		return []
	}
	x:=g(n)!
	if x==n {
		return [x]
	}
	mut l:=pollard_rho(x)!
	r:=pollard_rho(n/x)!
	l<<r
	l.sort()
	return l
}