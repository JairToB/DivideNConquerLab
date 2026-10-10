# Configuración del archivo de salida
set terminal pngcairo size 900,600 enhanced font "Arial,11"
set output 'grafica_fibonacci.png'

# Títulos y ejes
set title "Comparación de Tiempo de Ejecución: Fibonacci Lineal vs Logarítmico"
set xlabel "Posición en la secuencia (p)"
set ylabel "Tiempo de ejecución (microsegundos)"

# Estilo
set grid
set key top left

# Graficar columnas: 1=p, 2=Lineal, 3=Logarítmico
plot "datos_fibonacci.dat" using 1:2 with lines lw 2 title "Lineal O(n)", \
     "datos_fibonacci.dat" using 1:3 with lines lw 2 title "Logarítmico O(log n)"
