#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

typedef struct array {
  size_t capacity;
  size_t elements;
  double (*data)[2];
} Array;

void array_init(Array *array) {
  array->capacity = 1;
  array->elements = 0;
  array->data = malloc(sizeof(double[2]) * array->capacity);
}

void array_push(Array *array, double x, double y) {
  if (array->elements == array->capacity) {
    array->capacity *= 2;
    array->data = realloc(array->data, sizeof(double[2]) * array->capacity);
    assert(array->data != NULL);
  }
  array->data[array->elements][0] = x;
  array->data[array->elements][1] = y;
  array->elements++;
}

void array_pop(Array *array, double *x, double *y) {
  assert(array->elements > 0);
  array->elements--;
  *x = array->data[array->elements][0];
  *y = array->data[array->elements][1];
}

void array_shift(Array *array, double *x, double *y) {
  assert(array->elements > 0);
  *x = array->data[0][0];
  *y = array->data[0][1];
  for (size_t i = 0; i < array->elements - 1; i++) {
    array->data[i][0] = array->data[i + 1][0];
    array->data[i][1] = array->data[i + 1][1];
  }
  array->elements--;
}

void array_unshift(Array *array, double x, double y) {
  if (array->elements == array->capacity) {
    array->capacity *= 2;
    array->data = realloc(array->data, sizeof(double[2]) * array->capacity);
  }
  for (size_t i = array->elements; i > 0; i--) {
    array->data[i][0] = array->data[i - 1][0];
    array->data[i][1] = array->data[i - 1][1];
  }
  array->data[0][0] = x;
  array->data[0][1] = y;
  array->elements++;
}

void array_insert(Array *array, size_t index, double x, double y) {
  if (array->elements == array->capacity) {
    array->capacity *= 2;
    array->data = realloc(array->data, sizeof(double[2]) * array->capacity);
  }
  for (size_t i = array->elements; i > index; i--) {
    array->data[i][0] = array->data[i - 1][0];
    array->data[i][1] = array->data[i - 1][1];
  }
  array->data[index][0] = x;
  array->data[index][1] = y;
  array->elements++;
}

void array_delete(Array *array, size_t index) {
  for (size_t i = index; i < array->elements - 1; i++) {
    array->data[i][0] = array->data[i + 1][0];
    array->data[i][1] = array->data[i + 1][1];
  }
  array->elements--;
}

int main() {}
