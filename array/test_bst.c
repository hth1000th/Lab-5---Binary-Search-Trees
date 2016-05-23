#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "tree_traversal.h"
#include <test_bst.h>

int main(void) {

  test_Insert();

  puts("");
  puts("TESTING COMPLETE!");
  return 0;
}

void test_Insert() {
  int i;
  int *arr = malloc(7 * sizeof(int));
  puts("testing void Insert(int *arr, int index, int num)");
  for(i=0; i<7; i++) {
    arr[i] = -1;
  }
  Insert(arr, 0, 3);
  assert(arr[0] == 3);
  Insert(arr, 0, 7);
  assert(arr[2] == 7);
  Insert(arr, 0, 0);
  assert(arr[1] == 0);
  Insert(arr, 0, 2);
  assert(arr[4] == 2);
  Insert(arr, 0, 15);
  assert(arr[6] == 15);
  free(arr);
}
