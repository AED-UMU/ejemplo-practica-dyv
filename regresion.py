import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

# Leer CSV
df_mejor = pd.read_csv('resultados_mejor_caso.csv')
df_peor = pd.read_csv('resultados_peor_caso.csv')

# Preparar datos para regresión
df_mejor['logn'] = np.log(df_mejor['Longitud'])
df_peor['n'] = df_peor['Longitud']

# --- REGRESIÓN PARA MEJOR CASO: T(n) vs n ---
slope_mejor, intercept_mejor, r_mejor, p_mejor, _ = stats.linregress(df_mejor['logn'], df_mejor['MejorCaso'])

# --- REGRESIÓN PARA PEOR CASO: T(n) vs n log n ---
slope_peor, intercept_peor, r_peor, p_peor, _ = stats.linregress(df_peor['n'], df_peor['PeorCaso'])

# Resultados
print("   Regresión lineal MejorCaso ~ log n")
print(f"  Pendiente: {slope_mejor:.6f}")
print(f"  R²: {r_mejor**2:.4f}")
print(f"  MSE: {np.mean((df_mejor['MejorCaso'] - (slope_mejor * df_mejor['logn'] + intercept_mejor))**2):.4f}")
print(f"  p-valor: {p_mejor:.4e}\n")


print("   Regresión lineal PeorCaso ~ n")
print(f"  Pendiente: {slope_peor:.6f}")
print(f"  R²: {r_peor**2:.4f}")
print(f"  MSE: {np.mean((df_peor['PeorCaso'] - (slope_peor * df_peor['n'] + intercept_peor))**2):.4f}")
print(f"  p-valor: {p_peor:.4e}")


# 2. Ajuste mejor caso ~ Θ(log n)
plt.figure()
plt.plot(df_mejor['Longitud'], df_mejor['MejorCaso'], 'o', label='MejorCaso')
plt.plot(df_mejor['Longitud'], slope_mejor * df_mejor['logn'] + intercept_mejor, label=r'Ajuste $\Theta(\log n)$')
plt.xscale('log', base=2)
plt.xlabel('n')
plt.ylabel('Tiempo')
plt.title(r'Mejor caso $\sim \Theta(\log n)$')
plt.legend()
plt.grid(True)
plt.savefig('ajuster_mejor_log.pdf')

# 3. Ajuste peor caso ~ Θ(n)
plt.figure()
plt.plot(df_peor['Longitud'], df_peor['PeorCaso'], 'x', label='PeorCaso')
plt.plot(df_peor['Longitud'], slope_peor * df_peor['n'] + intercept_peor, label=r'Ajuste $\Theta(n)$')
plt.xscale('log', base=2)
plt.xlabel('n')
plt.ylabel('Tiempo')
plt.title(r'Peor caso $\sim \Theta(n)$')
plt.legend()
plt.grid(True)
plt.savefig('ajuster_peor_log.pdf')

# idem pero sin log

# 2. Ajuste mejor caso ~ Θ(log n)
plt.figure()
plt.plot(df_mejor['Longitud'], df_mejor['MejorCaso'], 'o', label='MejorCaso')
plt.plot(df_mejor['Longitud'], slope_mejor * df_mejor['logn'] + intercept_mejor, label=r'Ajuste $\Theta(\log n)$')
plt.xlabel('n')
plt.ylabel('Tiempo')
plt.title(r'Mejor caso $\sim \Theta(\log n)$')
plt.legend()
plt.grid(True)
plt.savefig('ajuster_mejor.pdf')

# 3. Ajuste peor caso ~ Θ(n)
plt.figure()
plt.plot(df_peor['Longitud'], df_peor['PeorCaso'], 'x', label='PeorCaso')
plt.plot(df_peor['Longitud'], slope_peor * df_peor['n'] + intercept_peor, label=r'Ajuste $\Theta(n)$')
plt.xlabel('n')
plt.ylabel('Tiempo')
plt.title(r'Peor caso $\sim \Theta(n)$')
plt.legend()
plt.grid(True)
plt.savefig('ajuster_peor.pdf')


