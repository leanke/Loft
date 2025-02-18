CC = gcc
CFLAGS = -Wall -Wextra -O2
OBJECTS = src/tree.o src/stack.o src/queue.o src/linked_list.o src/heap.o src/hash_table.o src/graph.o src/array.o

all: ../libleanke.a

../libleanke.a: $(OBJECTS)
	ar rcs $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) ../libleanke.a
