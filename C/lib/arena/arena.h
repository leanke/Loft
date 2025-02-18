#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>

typedef struct {
    char *base;
    size_t size;
    size_t used;
} Arena;

typedef struct {
    Arena *arena;
    size_t used;
} ArenaMarker;

void arena_init(Arena *arena, size_t size);
void arena_free(Arena *arena);
void *arena_alloc(Arena *arena, size_t size);
ArenaMarker arena_get_marker(Arena *arena);
void arena_reset_to_marker(ArenaMarker marker);
void arena_reset(Arena *arena);

#endif // ARENA_H
