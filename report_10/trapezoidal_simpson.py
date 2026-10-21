import math

# 被積分関数 f(x) = (1 - x) e^{-x}
def f(x):
    return (1.0 - x) * math.exp(-x)

a, b = -1.0, 2.0                                 # 積分区間 [a, b]
I_true = 2.0 * math.exp(-2.0) + math.exp(1.0)    # 真値 I = 2e^{-2} + e

# 台形公式
def trapezoidal(n):
    h = (b - a) / n
    s = 0.5 * (f(a) + f(b))
    for i in range(1, n):
        s += f(a + i * h)
    return h * s

# シンプソン公式（n は偶数）
def simpson(n):
    h = (b - a) / n
    s = f(a) + f(b)
    for i in range(1, n):
        s += (4.0 if i % 2 == 1 else 2.0) * f(a + i * h)
    return h / 3.0 * s

# n = 10 での計算
n = 10
T = trapezoidal(n)
S = simpson(n)
print(f"true value    : {I_true:.10f}")
print(f"trapezoid n={n}: {T:.10f}  error {abs(T - I_true):.3e}")
print(f"simpson   n={n}: {S:.10f}  error {abs(S - I_true):.3e}")

# 分割数を変えた誤差の推移
for n in [4, 8, 10, 20, 50, 100]:
    eT = abs(trapezoidal(n) - I_true)
    eS = abs(simpson(n) - I_true)
    print(f"{n:4d}  {eT:.3e}  {eS:.3e}")
