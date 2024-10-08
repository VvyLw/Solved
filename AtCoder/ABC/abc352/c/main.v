import os{input}
import arrays{sum}
import math{radians,cos,sin,hypot,max}

fn main() {
	n:=input('').int()
	mut g:=[]Pair[int,int]{len:n}
	for i in 0..n {
		p:=input('').split(' ').map(it.int())
		g[i]=mp(p[0],p[1])
	}
	mut ans:=i64(0)
	val:=sum(g.map(i64(it.first)))!
	for p in g {
		mut tmp:=val
		tmp+=p.second
		tmp-=p.first
		ans=max(ans,tmp)
	}
	println(ans)
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