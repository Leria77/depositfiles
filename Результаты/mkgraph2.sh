#!/usr/bin/gnuplot
set terminal png size 1000,600 enhanced font 'Arial, 16'
set output 'EXP6.png'

set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
set style line 2 linecolor rgb 'blue' linetype 1 linewidth 2


set border linewidth 1
set key top left
set grid
set mytics 0
set format y "%.6f"
set xlabel "Количество коллизий" font "Arial, 16"
set format x "%.0f"
set ylabel "Время выполнения(сек)" font "Arial, 16"
set xtics 100000 font "Arial, 12"
set ytics font "Arial, 12"
set rmargin 4
set tmargin 2
set mxtics

plot "C6KP.dat" using 1:2 title "KP hash" with linespoints ls 1,\
     "C6Add.dat" using 1:2 title "Add hash" with linespoints ls 2
