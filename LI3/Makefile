CFLAGS=-Wall -Wextra -g -ansi -pedantic -O2 
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))



GESTAUTS: $(OBJS)
	$(CC) $(CFLAGS) -o GESTAUTS $(OBJS) $(LIBS) 

clean:
	rm GESTAUTS *.o
