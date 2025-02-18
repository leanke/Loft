linux_gcc = gcc
linux_clang = clang
windows = x86_64-w64-mingw32-g++ # gcc
# LDFLAGS = -lncurses
CFLAGS = -I./include
LDFLAGS = -Wextra -Wall -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -fsanitize=address
DEBUGFLAGS = -Wextra -Wall -fsanitize=address

all: clean dev test # clean test
debug: clean debug_flag test


dev: src/main.o src/grid.o
	# $(linux_gcc) -o build/main_gcc src/main.o #$(LDFLAGS)
	$(linux_clang) -o build/main_clang src/main.o $(LDFLAGS)
	# $(windows) -o build/main_win src/main.o #$(LDFLAGS)

release: src/main.o src/grid.o
	$(linux_gcc) -o release/main_gcc src/main.o
	$(linux_clang) -o release/main_clang src/main.o
	$(windows) -o release/main_win src/main.o

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o
	
src/grid.o: src/grid.c
	$(CC) $(CFLAGS) -c src/grid.c -o src/grid.o
 
# src/new.o: src/new.c
	# $(CC) $(CFLAGS) -c src/new.c -o src/new.o

clean:
	rm -f build/main_clang

test:
	./build/main_clang

debug_flag: src/main.o src/grid.o
	$(linux_clang) $(CFLAGS) -g -c src/main.c -o src/main.o
	$(linux_clang) -o build/main src/main.o $(DEBUGFLAGS)
	gdb ./build/main_clang

