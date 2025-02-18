# Linking libleanke.a

1. Compile your source code:
   ```
   gcc -c main.c -o main.o
   ```
2. Link it with libleanke.a:
   ```
   gcc main.o -L/home/leanke/loft/C/utils/dataStructure -lleanke -o main
   ```
3. Run:
   ```
   ./main
   ```
