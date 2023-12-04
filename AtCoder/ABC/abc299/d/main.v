import os{input,flush}
import math{abs}
pub fn main() {
	mut ok:=1
	mut ng:=input('').int()
	for abs(ok-ng)>1 {
		mid:=abs(ok+ng)/2
		println('? ${mid}')
		flush()
		x:=input('').int()
		if x==0 { ok=mid }
		else { ng=mid }
	}
	println('! ${ok}')
}