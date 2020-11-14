all: interpolations.exe

interpolations.exe: main.o Error_value.o c2f.o f2c.o Results_to_file.o Function_2B_interpolated.o
	gcc -o interpolations.exe main.o Error_value.o c2f.o f2c.o Results_to_file.o Function_2B_interpolated.o -lm

main.o: main.c Error_value.h c2f.h f2c.h Results_to_file.h Function_2B_interpolated.h
	gcc -c main.c

Error_value.o: Error_value.c Error_value.h
	gcc -c Error_value.c

c2f.o: c2f.c c2f.h
	gcc -c c2f.c

f2c.o: f2c.c f2c.h
	gcc -c f2c.c

Function_2B_interpolated.o: Function_2B_interpolated.c Function_2B_interpolated.h
		gcc -c Function_2B_interpolated.c

Results_to_file.o: Results_to_file.c Results_to_file.h Function_2B_interpolated.h Error_value.h
	gcc -c Results_to_file.c

clean:
	rm -rf interpolations *.o *~
