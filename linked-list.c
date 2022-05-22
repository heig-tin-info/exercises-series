#include <stdlib.h>
#include <stdint.h>

typedef struct node {
  double value;
  struct node *next;
} Node;

typedef struct list {
  size_t count;
  Node *head;
  Node *tail;
} List;

int push(List *list, double value) {
  Node *node = malloc(sizeof(Node));
  if (node == NULL) {
    return -1;
  }
  node->value = value;
  node->next = NULL;
  if (list->count == 0) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
  list->count++;
  return 0;
}

void display(List *list) {
  Node *node = list->head;
  while (node != NULL) {
    printf("%g ", node->value);
    node = node->next;
  }
  printf("\n");
}

double mean(List *list) {
  double sum = 0;
  Node *node = list->head;
  while (node != NULL) {
    sum += node->value;
    node = node->next;
  }
  return sum / list->count;
}

int compare(List *a, List *b) {
  if (a->count != b->count) {
    return -1;
  }
  Node *node_a = a->head;
  Node *node_b = b->head;
  while (node_a != NULL) {
    if (node_a->value != node_b->value) {
      return -1;
    }
    node_a = node_a->next;
    node_b = node_b->next;
  }
  return 0;
}