objects = program.o grid.o read_data.o initialize.o output.o delete_memory.o \
	flux.o update.o

run:$(objects)
	cc -Wall -o run $(objects) -lm 


program.o:program.c definitions.h
grid.o:grid.c definitions.h
delete_memory.o:delete_memory.c definitions.h
read_data.o:read_data.c definitions.h
output.o:output.c definitions.h
initialize.o:initialize.c definitions.h
update.o:update.c definitions.h
flux.o:flux.c definitions.h

.PHONY:clean
clean:
	rm -rf $(objects)
