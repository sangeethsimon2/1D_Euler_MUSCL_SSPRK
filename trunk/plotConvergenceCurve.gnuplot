set xlabel "log(dx)"
set ylabel "log(L2 error)"
set autoscale
set style line 1 lt 1 lw 3 pt 3 linecolor rgb "red"
plot filename using 1:2 w lines title "Convergence plot"
set terminal postscript portrait enhanced mono dashed lw 1 'Helvetica' 14
set output 'ConvergencePlot.pdf'
replot
#set terminal wxt persist 