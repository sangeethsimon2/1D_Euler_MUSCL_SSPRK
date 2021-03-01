objects = program.o grid.o read_data.o boundaryCondition.o copySolution.o timestep.o updateSecondOrder.o initialize.o output.o delete_memory.o \
	flux.o update.o localizedCosine.o line.o computeError.o computeFlux.o computeFluxAtBoundary.o outputOldValues.o outputForPrint.o

run:$(objects)
	g++ -Wall -o run $(objects) -lm 


program.o:program.c definitions.h
grid.o:grid.c definitions.h
delete_memory.o:delete_memory.c definitions.h
read_data.o:read_data.c definitions.h
output.o:output.c definitions.h
initialize.o:initialize.c definitions.h
update.o:update.c definitions.h
flux.o:flux.c definitions.h

boundaryCondition.o:boundaryCondition.c definitions.h
copySolution.o:copySolution.c definitions.h
timestep.o:timestep.c definitions.h
updateSecondOrder.o:updateSecondOrder.c definitions.h
localizedCosine.o:localizedCosine.c definitions.h
line.o:line.c definitions.h
computeError.o:computeError.c definitions.h
computeFlux.o:computeFlux.c definitions.h
computeFluxAtBoundary.o:computeFluxAtBoundary.c definitions.h
outputOldValues.o:outputOldValues.c definitions.h
outputForPrint.o:outputForPrint.c definitions.h


.PHONY:clean
clean:
	rm -rf $(objects)
