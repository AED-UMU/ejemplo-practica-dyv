# Ejemplo práctica DyV

Pequeña práctica ejemplo de Divide y Vencerás (DyV) en C++ para calcular la longitud de la subsecuencia no estrictamente creciente contigua más larga, con pruebas, generación de tiempos y un script de regresión/visualización en Python.

## Estructura

- `dyv.h`, `dyv.cpp`: implementación del algoritmo (DyV e iterativo).
- `tests_unitarios.cpp`: tests unitarios básicos sobre casos representativos.
- `tests_oraculo.cpp`: compara la salida de DyV con una versión iterativa (oráculo).
- `tiempos.cpp`: genera datos de tiempos para mejor/peor caso y escribe `resultados.csv`.
- `regresion.py`: realiza regresión lineal y guarda gráficas en PDF a partir de `resultados.csv`.
- `makefile`: reglas de compilación y limpieza.

## Requisitos

Herramientas del sistema (Linux):

- g++ (C++11 o superior)
- make
- Python 3.8+ y `pip`

Instalación rápida en Ubuntu/Debian:

```bash
sudo apt update
sudo apt install -y g++ make python3 python3-pip
```

Dependencias Python (para `regresion.py`):

```bash
python3 -m pip install --upgrade pip
python3 -m pip install pandas numpy matplotlib scipy
```

Opcional (recomendado): entorno virtual

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install pandas numpy matplotlib scipy
```

## Compilación (C++)

Compilar todo (tests y tiempos):

```bash
make
```

Objetivos disponibles:

- `make tests_unitarios` → binario `./tests_unitarios`
- `make tests_oraculo`   → binario `./tests_oraculo`
- `make tiempos`         → binario `./tiempos`
- `make clean`           → borrar objetos y binarios

## Ejecución

Ejecutar tests unitarios:

```bash
./tests_unitarios
```

Ejecutar test con oráculo (compara con la versión iterativa):

```bash
./tests_oraculo
```

Generar tiempos y CSV (mejor/peor caso):

```bash
./tiempos
ls -l resultados.csv
```

## Análisis y gráficas (opcional)

Con `resultados.csv` generado, lanzar el script de regresión y guardar gráficas en PDF:

```bash
python3 ./regresion.py
```

El script imprime métricas (pendiente, $R^2$, $MSE$, etc.) y crea los ficheros:

- `scatter_plot_log.pdf`, `ajuster_mejor_log.pdf`, `ajuster_peor_log.pdf`
- `scatter_plot.pdf`, `ajuster_mejor.pdf`, `ajuster_peor.pdf`

## Limpieza

```bash
make clean
```
