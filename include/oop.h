#ifndef _OOP_H
#define _OOP_H 1

#include <stdint.h>

typedef enum {
  NORTH, SOUTH, EAST, WEST
} direction;

typedef struct {
  char *class;
  int (*init)(void *self);
  void (*destroy)(void *self);
  void (*describe)(void *self);
  uint8_t (*take_action)(void *self, void *target);
  int (*recv_action)(void *self, uint8_t parameter);
  void (*move_action)(void *self, direction dir);
} object;

int object_init(void *self);
void object_destroy(void *self);
void object_describe(void *self);
uint8_t take_action(void *self, void *target);
int recv_action(void *self, uint8_t parameter);
void move_action(void *self, direction dir);
void *object_new(size_t size, object proto, char *class);

#define NEW(T, N) object_new(sizeof(T), T##_proto, N)
#define _(N) proto.N

#endif