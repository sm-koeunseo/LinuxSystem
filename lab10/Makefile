sort: sort.o copy.o
	gcc -o sort sort.o copy.o
sort.o : sort.c copy.h
	gcc -c sort.c
copy.o : copy.c
	gcc -c copy.c
