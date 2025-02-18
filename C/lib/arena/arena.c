#include "arena.h"
#include <stdlib.h>
#include <string.h>

void arena_init(Arena *arena, size_t size) {
    arena->base = (char *)malloc(size);
    arena->size = size;
    arena->used = 0;
}

void arena_free(Arena *arena) {
    free(arena->base);
    arena->base = NULL;
    arena->size = 0;
    arena->used = 0;
}

void *arena_alloc(Arena *arena, size_t size) {
    if (arena->used + size > arena->size) {
        return NULL; // Not enough memory
    }
    void *ptr = arena->base + arena->used;
    arena->used += size;
    return ptr;
}

ArenaMarker arena_get_marker(Arena *arena) {
    ArenaMarker marker;
    marker.arena = arena;
    marker.used = arena->used;
    return marker;
}

void arena_reset_to_marker(ArenaMarker marker) {
    marker.arena->used = marker.used;
}

void arena_reset(Arena *arena) {
    arena->used = 0;
}
