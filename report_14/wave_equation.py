"""
Wave equation solver: d^2z/dt^2 = c * d^2z/dx^2  (c = 2)
Finite-difference method with cr^2 = 1.
"""
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D   # noqa: F401

plt.rcParams["font.family"] = "MS Gothic"

# ---------------- settings ----------------
c = 2.0
L = 4.0
h = 0.5
N = int(L / h)                     # number of spatial divisions
k = h / np.sqrt(c)                 # chosen so that cr^2 = 1
M = 16                            # number of time steps

x = np.linspace(0.0, L, N + 1)
z = np.zeros((M + 1, N + 1))

# ---------------- initial condition ----------------
z[0, :] = np.where(x <= 2.0, 0.5 * x, -0.5 * x + 2.0)

# boundary condition
z[:, 0] = 0.0
z[:, N] = 0.0

# j = 1 row (uses z_{i,-1} = z_{i,1} from dz/dt(x,0) = 0)
z[1, 1:N] = 0.5 * (z[0, 2:N + 1] + z[0, 0:N - 1])

# j >= 2 rows (simplified scheme for cr^2 = 1)
for j in range(1, M):
    z[j + 1, 1:N] = z[j, 2:N + 1] + z[j, 0:N - 1] - z[j - 1, 1:N]

# ---------------- print results ----------------
t = k * np.arange(M + 1)
print(" j      t_j      " + "  ".join(f"{xi:6.3f}" for xi in x))
for j in range(M + 1):
    row = "  ".join(f"{zi:6.3f}" for zi in z[j, :])
    print(f"{j:2d}  {t[j]:7.4f}  {row}")

# ---------------- figure 1: waveform at each time ----------------
fig1 = plt.figure(figsize=(5, 4))
for j in range(0, M + 1, 2):
    plt.plot(x, z[j, :], marker="o", markersize=3, label=f"j={j}")
plt.xlabel("x")
plt.ylabel("z(x, t_j)")
plt.title("Waveform at each time step")
plt.legend(fontsize=6, ncol=3)
plt.grid(True)
plt.tight_layout()
fig1.savefig("fig_wave.pdf")

# ---------------- figure 2: 3D plot ----------------
X, T = np.meshgrid(x, t)
fig2 = plt.figure(figsize=(5, 4))
ax = fig2.add_subplot(111, projection="3d")
ax.plot_surface(X, T, z, cmap="viridis", edgecolor="k", linewidth=0.2)
ax.set_xlabel("x")
ax.set_ylabel("t")
ax.set_zlabel("z(x, t)")
ax.set_title("3D plot of z(x, t)")
plt.tight_layout()
fig2.savefig("fig_3d.pdf")
