#include "llists.h"
#define MAX 10

int main() {
  int a[MAX] = {11, 232, 2353, 6344, 74575, 766, 742447, 23458, 75649, 13425230};
  Node *head = create_list(a, MAX);
  print_ll(head);
  return 0;
}
