GESTAUTS : catalogo.o index.o main.o parser.o queries.o stats.o
	cc -Wall -Wextra -g -ansi -pedantic -O2 -o GESTAUTS catalogo.o index.o main.o parser.o queries.o stats.o

catalogo.o : catalogo.c catalogo.h parser.h
	cc -Wall -Wextra -g -ansi -pedantic -O2 -c -o catalogo.o catalogo.c

index.o : index.c index.h parser.h
	cc -Wall -Wextra -g -ansi -pedantic -O2 -c -o index.o index.c


parser.o: parser.c parser.h
	cc -Wall -Wextra -g -ansi -pedantic -O2 -c -o parser.o parser.c

main.o : main.c queries.h
	cc -Wall -Wextra -g -ansi -pedantic -O2 -c -o main.o main.c

queries.o : queries.c queries.h index.h parser.h stats.h catalogo.h
	cc -Wall -Wextra -g -ansi -pedantic -O2 -c -o queries.o queries.c

stats.o : stats.c stats.h parser.h
	cc -Wall -Wextra -g -ansi -pedantic -O2 -c -o stats.o stats.c






clean:
	rm GESTAUTS *.o
