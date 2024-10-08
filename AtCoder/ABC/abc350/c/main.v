import os{input}
import math{radians,cos,sin,hypot}

fn main() {
	n:=input('').int()
	mut a:=input('').split(' ').map(it.int()-1)
	mut id:=[]int{len:n}
	for i in 0..n {
		id[a[i]]=i
	}
	mut ans:=[]Pair[int,int]{}
	for i in 0..n {
		if i==a[i] {
			continue
		}
		j:=id[i]
		ans<<mp(i,j)+mp(1,1)
		a[i],a[j]=a[j],a[i]
		id[a[i]]=i
		id[a[j]]=j
	}
	//eprintln(id)
	println(ans.len)
	for p in ans {
		println('$p.first $p.second')
	}
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
pub fn (p Pair[T,T]) lcm() i64 { return math.lcm(p.first,p.second) }
pub fn (p Pair[T,T]) gcd() i64 { return math.gcd(p.first,p.second) }
pub fn (p Pair[T,U]) swap() Pair[U,T] { return Pair[U,T]{p.second,p.first} }