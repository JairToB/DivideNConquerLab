# DivideNConquerLab

## C++ Algorithm Benchmarking and Visualization with Gnuplot

This repository contains experiments to measure execution times and compare the algorithmic complexity of different approaches to common problems in C++. Gnuplot is used to visualize the results and generate performance comparison graphs.

## Requirements

* **C++ Compiler:** `g++` (support for C++11 or later)
* **Gnuplot:** Used to generate graphs from experimental data.

## Compilation and Execution

### 1. Exponentiation Algorithms (`powers.cpp`)

```bash
g++ -O2 powers.cpp -o program_powers
./program_powers > datos.dat
gnuplot script_powers.gp
```

**Generated output:** `grafica.png`

### 2. Fibonacci: Linear \(O(n)\) vs. Logarithmic \(O(\log n)\) (`fibonacci.cpp`)

```bash
g++ -O2 fibonacci.cpp powerMatrix_2x2.cpp -o program_fibonacci
./program_fibonacci > datos_fibonacci.dat
gnuplot script_fibonacci.gp
```

**Generated output:** `grafica_fibonacci.png`

### 3. Matrix Multiplication: Standard vs. Strassen (`matrixMultiplication.cpp`)

```bash
g++ -O2 matrixMultiplication.cpp -o program_matrix
./program_matrix > data_matrixMultiplication.dat
gnuplot script_matrixMultiplication.gp
```

**Generated output:** `graficoComparacion.png`

## Cleaning Generated Files

Run the following command to remove compiled executables and experimental data files:

```bash
rm -f program_powers program_fibonacci program_matrix \
      datos.dat datos_fibonacci.dat data_matrixMultiplication.dat
```
