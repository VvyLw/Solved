import os{input}

pub fn t2[T](ls []T) (T,T) { return ls[0],ls[1] }
fn main() {
	n,m:=t2(input('').split(' ').map(it.int()))
	mut uf:=new_uf(n)
	for _ in 0..m {
		a,b:=t2(input('').split(' ').map(it.int()-1))
		uf.unite(a,b)
	}
	mut ans:=i64(0)
	for g in uf.groups() {
		ans+=i64(g.len)*(g.len-1)/2
	}
	ans-=m
	println(ans)
}

pub struct UnionFind {
mut:
	par []int
}
pub fn new_uf(n int) UnionFind {
	return UnionFind{
		par: []int{len:n,init:-1}
	}
}
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
	return res.filter(it.len!=0)
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