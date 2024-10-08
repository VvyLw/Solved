import os { input }

fn main() {
	nm := input('').split(' ').map(it.int())
	n, m := nm[0], nm[1]
	mut uf := WeightedUnionFind.new(n)
	for _ in 0 .. m {
		uvw := input('').split(' ').map(it.int())
		u, v, w := uvw[0] - 1, uvw[1] - 1, uvw[2]
		uf.unite(u, v, w)
	}
	x := []int{len: n, init: index}.map(uf.get(it) - uf.get(0))
	println(x.map(it.str()).join(' '))
}

pub struct WeightedUnionFind {
mut:
	par    []int
	weight []i64
}

pub fn WeightedUnionFind.new(n int) WeightedUnionFind {
	return WeightedUnionFind{
		par: []int{len: n, init: -1}
		weight: []i64{len: n}
	}
}

fn (mut uf WeightedUnionFind) str() string {
	return '${uf.groups()}'
}

pub fn (mut uf WeightedUnionFind) root(i int) int {
	if uf.par[i] < 0 {
		return i
	}
	r := uf.root(uf.par[i])
	uf.weight[i] += uf.weight[uf.par[i]]
	uf.par[i] = r
	return r
}

pub fn (mut uf WeightedUnionFind) get(i int) i64 {
	uf.root(i)
	return uf.weight[i]
}

pub fn (mut uf WeightedUnionFind) unite(i int, j int, wg i64) int {
	mut w := wg + uf.get(i) - uf.get(j)
	mut x := uf.root(i)
	mut y := uf.root(j)
	if x == y {
		return if w == 0 { 0 } else { -1 }
	}
	if uf.par[x] > uf.par[y] {
		x, y = y, x
		w = -w
	}
	uf.par[x] += uf.par[y]
	uf.par[y] = x
	uf.weight[y] = w
	return 1
}

pub fn (mut uf WeightedUnionFind) size(i int) int {
	return -uf.par[uf.root(i)]
}

pub fn (mut uf WeightedUnionFind) groups() [][]int {
	n := uf.par.len
	mut res := [][]int{len: n, init: []int{}}
	for i in 0 .. n {
		res[uf.root(i)] << i
	}
	return res.filter(it.len > 0)
}
