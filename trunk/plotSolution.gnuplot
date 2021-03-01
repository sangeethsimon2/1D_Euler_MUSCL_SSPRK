set terminal postscript 
set output "solutionPlot.pdf"
set title "Initial vs final plot"
set xlabel "Location"
set ylabel "Solution"
set key top left
set autoscale

plot "density_initial.dat" using 1:2 with lines ls 1 title "Initial" , \
"density_final.dat" using 1:2  with lines ls 2 title "Final"
set output 
