#include <stdio.h>
#include <stdlib.h>

typedef struct N {
  int value;
  struct N* next;
} Node;

Node* create_list(int* vals, int n) {
  int i;
  Node *new, *rider, *head;
  head = malloc(sizeof(Node));
  if (head == NULL) {
    printf("Can't allocate memory, exiting...");
    exit(0);
  }
  head->value = *vals;
  head->next = NULL;
  rider = head;
  for (i = 1; i < n; ++i) {
    new = malloc(sizeof(Node));
    if (new == NULL) {
      printf("Can't allocate memory, exiting...");
      exit(0);
    }
    new->value = *(vals + i);
    new->next = NULL;
    rider->next = new;
    rider = rider->next;
  }
  return head;
}

void print_ll(Node *rider) {
  while (rider->next != NULL) {
    printf("%d\n", rider->value);
    rider = rider->next;
  }
  printf("\n");
  return;
}
