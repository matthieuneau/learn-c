#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct {
  int *data;
  unsigned int size;
  unsigned int capacity;
} DynamicArray;

DynamicArray *init_array(unsigned int initial_capacity);
void append(DynamicArray *arr, int value);
void removeAt(DynamicArray *arr, unsigned int index);
void freeArray(DynamicArray *arr);
void printArray(DynamicArray *arr);

#endif
