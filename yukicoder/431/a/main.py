import numpy as np
a=np.array(list(map(int,input().split())))
b=np.array(list(map(int,input().split())))
print(*np.cross(a,b))