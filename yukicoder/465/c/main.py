N, Q = map(int, input().split())
X = [int(input()) for _ in range(N)]

if N + len(set(X)) > Q:
    print("No")
    exit()

queries = []
for x in set(X):
    queries.append((1, x, x))

for x in X:
    queries.append((2, x))

queries.extend((1, 1, 1) for _ in range(Q - len(queries)))

print("Yes")
for query in queries:
    print(*query)
