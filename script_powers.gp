# Configuración general de la gráfica
set title "Comparación de Tiempo de Ejecución: O(n) vs O(log n)"
set xlabel "Exponente (n)"
set ylabel "Tiempo (microsegundos)"
set grid
set key top left

# Opcional: Generar imagen PNG de alta calidad
set terminal pngcairo size 800,600 enhanced font 'Sans,10'
set output 'grafica.png'

# Graficar Columna 1 (n) vs Columna 2 (Secuencial) y Columna 3 (Logarítmico)
plot "datos.dat" using 1:2 with linespoints title "Secuencial O(n)" lw 2 pt 7, \
     "datos.dat" using 1:3 with linespoints title "Logarítmico O(log n)" lw 2 pt 7
