set xlabel "dx"
set ylabel "L2 error"
set logscale x
set logscale y
#set autoscale
#set style line 1 lt 1 lw 3 pt 3 linecolor rgb "red"
plot filename using 1:2 w points title "Convergence plot", x**1, 100*x**2
set terminal postscript portrait enhanced mono dashed lw 1 'Helvetica' 14
set output 'ConvergencePlot.pdf'
replot
#set terminal wxt persist 
