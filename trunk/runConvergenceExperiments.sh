#!/bin/bash

#Compile the executable within src
cd src
make
cd ../

#declare some working arrays
declare -a ErrorArray
declare -a GridArray
declare -a GridSpacing 

#open a text file for storing the convergence data
touch ConvergenceData.dat

#Grid=$(seq 10 10 50)
#input grids needed here
#Grid=(10 20 40 80 160)
source inputParameters.sh

#Obtain length of the grid array
len=${#Grid[@]}

#Compute log(gridspacing) and store it in GridArray[]
for ((i=0;i<$len;i++))  
  do
	 dx=$(echo "scale=5; 1.0 / ${Grid[$i]}" | bc)
	 Random=$(echo "l($dx)" | bc -l)
 	 GridArray[$i]=$Random
   done


index=0
for grid in ${Grid[@]}
  do
    #setup each grid directory Grid_N where N= number of grid points
    mkdir Grid_$grid
    cd Grid_$grid
    #copy input data file with appropriate grid size corresponding to the directory name
    sed s/Grid/$grid/g ../data.template > data 

    #Copy the executable
    rsync -azh ../src/run .
    ./run

    #Extract the log(sqrt(L2 error)) and store it in ErrorArray[] 
    value=$(cat error.dat | grep "Error"| cut -d "=" -f2)    
    ErrorArray[$index]=$value
    index=$(($index+1))
    
    #Plot the solution using density_initial.dat and density_final.dat files that are outputed from the program
    rsync -azh ../plotSolution.gnuplot .
    gnuplot  plotSolution.gnuplot

    cd ../
  done

  #Output the data needed for convergence analysis: Log(dx) and Log(sqrt(L2 error))  
printf '%s \t %s\n' "#Log(sqrt(dx))" "Log(Error)" > ConvergenceData.dat
len=${#GridArray[@]}
for ((j=0;j<$len;j++))  
  do
    printf '%0.6f \t %.6f\n' "${GridArray[j]}" "${ErrorArray[j]}">>ConvergenceData.dat
  done

unset GridArray
unset ErrorArray 

#Plot the convergence curve
gnuplot -e "filename='ConvergenceData.dat'" plotConvergenceCurve.gnuplot

