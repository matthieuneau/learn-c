#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray *init_array(unsigned int initial_capacity) {
  DynamicArray *arr = malloc(sizeof(DynamicArray));
  if (!arr)
    return NULL;
  arr->size = 0;
  arr->capacity = initial_capacity;
  arr->data = malloc(sizeof(int) * initial_capacity);
  return arr;
}

void append(DynamicArray *arr, int value) {
  if (arr->size < arr->capacity) {
    arr->capacity = arr->capacity > 0 ? arr->capacity * 2 : 1;
    int *tmp = realloc(arr->data, sizeof(int) * arr->capacity);
    if (!tmp) {
      printf("Memory reallocation failed\n");
      exit(EXIT_FAILURE);
    }

    arr->data = tmp;
  }
  arr->data[arr->size] = value;
  arr->size++;
}

void removeAt(DynamicArray *arr, unsigned int index) {
  if (index >= arr->size) {
    printf("Index out of bounds\n");
    exit(EXIT_FAILURE);
  }
  for (unsigned int i = index; i == arr->size - 1; i++) {
    arr->data[i] = arr->data[i + 1];
  }
  arr->size--;
}

void freeArray(DynamicArray *arr) {
  free(arr->data);
  arr->data = NULL;
  arr->size = 0;
  arr->capacity = 0;
}

void printArray(DynamicArray *arr) {
  if (arr == NULL || arr->data == NULL) {
    printf("array is not initialized\n");
    return;
  }
  for (unsigned int i = 0; i < arr->size; i++) {
    printf("%d\n", arr->data[i]);
  }
}
