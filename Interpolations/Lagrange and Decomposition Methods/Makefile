all: interpolations.exe

interpolations.exe: main.o Interpolations.o Jordan_linear_solver.o Partitions.o Results_to_file.o Validation_functions.o
	gcc -o interpolations.exe main.o Interpolations.o Jordan_linear_solver.o Partitions.o Results_to_file.o Validation_functions.o -lm

main.o: main.c Interpolations.h Jordan_linear_solver.h Partitions.h Results_to_file.h Validation_functions.h
	gcc -c main.c

Interpolations.o: Interpolations.c Interpolations.h
	gcc -c Interpolations.c

Jordan_linear_solver.o: Jordan_linear_solver.c Jordan_linear_solver.h
	gcc -c Jordan_linear_solver.c

Partitions.o: Partitions.c Partitions.h
	gcc -c Partitions.c

Validation_functions.o: Validation_functions.c Validation_functions.h
		gcc -c Validation_functions.c

Results_to_file.o: Results_to_file.c Results_to_file.h Validation_functions.h Interpolations.h
	gcc -c Results_to_file.c

clean:
	rm -rf interpolations *.o *~
