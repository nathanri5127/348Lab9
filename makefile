CC=g++
CFLAGS=-c
OBJECTS = 348Lab8.cpp
all: prog run
prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog
%.o: %.cpp
	$(CC) $(CFLAGS) $<
run: prog
	./prog
clean:
	rm -rf *.o
	rm -rf prog