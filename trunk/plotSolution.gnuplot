set terminal postscript 
set output "solutionPlotRho.pdf"
set title "Initial vs final plot"
set xlabel "Location"
set ylabel "Solution"
set key top left
set autoscale

plot "output_initial.dat" using 1:2 with lines ls 1 title "Initial" , \
"output_final.dat" using 1:2  with points ls 2 title "Final"
set output

set output "solutionPlotU.pdf"
plot "output_initial.dat" using 1:3 with lines ls 1 title "Initial" , \
"output_final.dat" using 1:3  with points ls 2 title "Final"
set output 

set output "solutionPlotP.pdf"
plot "output_initial.dat" using 1:4 with lines ls 1 title "Initial" , \
"output_final.dat" using 1:4  with points ls 2 title "Final"
set output 