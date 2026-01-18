n, a, b = map(int, input().split())

I = 0
F = 1
for i in range(2, n+2):
    F *= i

xa = a
xb = b
for i in range(0, n+1):
    k = int(input())
    I += F*k*(xb-xa)//(i+1)
    xa *= a
    xb *= b

print(int(I//F))