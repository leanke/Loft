# Arena Memory Management

The arena memory management system provides a simple and efficient way to allocate and manage memory. It allows you to request an initial block of memory and divide it into different lifetimes using markers.

## Structures

### Arena

```cpp
typedef struct {
    char *base;
    size_t size;
    size_t used;
} Arena;
```

- `base`: Pointer to the beginning of the memory block.
- `size`: Total size of the memory block.
- `used`: Amount of memory used.

### ArenaMarker

```cpp
typedef struct {
    Arena *arena;
    size_t used;
} ArenaMarker;
```

- `arena`: Pointer to the arena.
- `used`: Amount of memory used at the time the marker was created.

## Functions

### arena_init

```cpp
void arena_init(Arena *arena, size_t size);
```

Initializes an arena with a specified size.

### arena_free

```cpp
void arena_free(Arena *arena);
```

Frees the memory allocated for the arena.

### arena_alloc

```cpp
void *arena_alloc(Arena *arena, size_t size);
```

Allocates a block of memory of the specified size from the arena.

### arena_get_marker

```cpp
ArenaMarker arena_get_marker(Arena *arena);
```

Gets a marker representing the current state of the arena.

### arena_reset_to_marker

```cpp
void arena_reset_to_marker(ArenaMarker marker);
```

Resets the arena to the state represented by the marker.

### arena_reset

```cpp
void arena_reset(Arena *arena);
```

Resets the arena, making all previously allocated memory available again.

## Example Usage

```cpp
#include "arena.h"
#include <stdio.h>

int main() {
    Arena arena;
    arena_init(&arena, 1024); // Initialize arena with 1024 bytes

    int *numbers = (int *)arena_alloc(&arena, 10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        numbers[i] = i;
    }

    ArenaMarker marker = arena_get_marker(&arena);

    char *text = (char *)arena_alloc(&arena, 50);
    snprintf(text, 50, "Hello, Arena!");

    printf("%s\n", text);

    arena_reset_to_marker(marker); // Reset to marker, freeing 'text' but keeping 'numbers'

    arena_reset(&arena); // Reset the entire arena, freeing all memory

    arena_free(&arena); // Free the arena

    return 0;
}
