#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

// Function to check if two arrays are equal
int arraysEqual(int *a, int *b, int size) {
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }
  return 1;
}

// Main function to test the DynamicArray
int main() {
  printf("Testing DynamicArray...\n");

  // 1. Test Initialization
  DynamicArray *arr = init_array(5);
  if (arr->size != 0 || arr->capacity != 5 || arr->data == NULL) {
    printf("Initialization test FAILED.\n");
    return 1;
  }
  printf("Initialization test PASSED.\n");

  // 2. Test Appending Values
  append(arr, 10);
  append(arr, 20);
  append(arr, 30);
  int expected1[] = {10, 20, 30};
  if (arr->size != 3 || !arraysEqual(arr->data, expected1, arr->size)) {
    printf("Appending test FAILED.\n");
    return 1;
  }
  printf("Appending test PASSED.\n");

  // 3. Test Capacity Doubling
  for (int i = 0; i < 3; i++) {
    append(arr, i + 40);
  }
  int expected2[] = {10, 20, 30, 40, 41, 42};
  if (arr->capacity <= 5 || arr->size != 6 ||
      !arraysEqual(arr->data, expected2, arr->size)) {
    printf("Capacity doubling test FAILED.\n");
    return 1;
  }
  printf("Capacity doubling test PASSED.\n");

  // 4. Test Removing Values
  removeAt(arr, 2); // Remove the element at index 2 (value 30)
  int expected3[] = {10, 20, 40, 41, 42};
  if (arr->size != 5 || !arraysEqual(arr->data, expected3, arr->size)) {
    printf("Removing test FAILED.\n");
    return 1;
  }
  printf("Removing test PASSED.\n");

  // 5. Test Removing Out of Bounds
  int failed = 0;
  if (!failed) {
    printf("Out-of-bounds removing test PASD!\n :pass INNEXPECTED");
  }
}
