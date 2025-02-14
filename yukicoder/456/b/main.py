from sympy import Matrix, ZZ
from sympy.matrices.normalforms import smith_normal_form
a, b = map(int, input().split())
c, d = map(int, input().split())
m = Matrix([[a, b],[c, d]])
s = smith_normal_form(m, domain = ZZ)
print(s[0], s[3])