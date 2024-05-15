fn main() {
	mut y,mut m, mut d, mut x,mut c:=2001,1,1,0,0
	for c<666 {
		d++
		if m==2 {
			if y%4==0 {
				if d>29 {
					d=1
					m++
				}
			} else {
				if d>28 {
					d=1
					m++
				}
			}
		} else if m in [1,3,5,7,8,10,12] {
			if d>31 {
				d=1
				m++
			}
		} else {
			if d>30 {
				d=1
				m++
			}
		}
		if m>12 {
			m=1
			y++
		}
		x++
		x%=7
		if x==5 && d==13 {
			c++
		}
	}
	println('$y $m $d')
}