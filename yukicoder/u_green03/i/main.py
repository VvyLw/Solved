# evalが悪いだけ説ある
# そもそも線形計画でmin, maxが使えないよという話(ぐぬぬ)
# from pulp import LpProblem, LpVariable, LpInteger, LpMinimize, value, PULP_CBC_CMD
# _,y=map(int,input().split())
# s=list(input().split())
# prob=LpProblem(sense=LpMinimize)
# x=LpVariable('x',lowBound=0,cat=LpInteger)
# sk=[]
# op = {'+': lambda x,y: x+y,
#       'max': lambda x,y: max(x,y),
#       'min': lambda x,y: min(x,y)}
# for t in s:
#     if t in op:
#         b,a=sk.pop(),sk.pop()
#         sk.append(op[t](a,b))
#     else: sk.append(x if t=="X" else int(t))
# prob+=sk[0]==y
# prob.solve(PULP_CBC_CMD(msg=False))
# print(int(value(x)) if prob.status==1 else -1)

# 非線形計画だと厳密な整数解は出しにくいよという話(ぐぬぬ)
# ワンチャンいけるかも(無理でした)
# from scipy.optimize import minimize
# _,y=map(int,input().split())
# s=list(input().split())
# def f(x):
#     sk=[]
#     op = {'+': lambda x,y: x+y,
#           'max': lambda x,y: max(x,y),
#           'min': lambda x,y: min(x,y)}
#     for t in s:
#         if t in op:
#             b,a=sk.pop(),sk.pop()
#             sk.append(op[t](a,b))
#         else: sk.append(x if t=="X" else int(t))
#     return sk[0]
# def g(x): return abs(f(x[0])-y)
# ret=minimize(g,x0=[0],method='Nelder-Mead')
# apx=int(ret.x[0])
# if f(apx)==y: print(apx)
# else: print(-1)

# ニア、僕の勝ちだ
_,y=map(int,input().split())
s=list(input().split())
def f(x):
    sk=[]
    op={'+': lambda x,y: x+y,
        'max': lambda x,y: max(x,y),
        'min': lambda x,y: min(x,y)}
    for t in s:
        if t in op:
            b,a=sk.pop(),sk.pop()
            sk.append(op[t](a,b))
        else: sk.append(x if t=="X" else int(t))
    return sk[0]
ok,ng=(1<<61)-1,-1
while abs(ok-ng)>1:
    x=(ok+ng)//2
    # print(x, f(x))
    if f(x)>=y: ok=x
    else: ng=x
print(ok if f(ok)==y else -1)