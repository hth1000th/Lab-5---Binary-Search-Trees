#include <stdio.h>
#include <stdlib.h>
#include "tree_traversal.h"

int main(void)
{
  int i;
  int num = 0;
  int *arr = malloc(1000 * sizeof(int));

  // default to empty node;
  for(i=0; i<1000; i++) {
    arr[i] = -1;
  }

  while(num>=0) {
    printf("Enter the integer (Negative number to stop): ");
    scanf("%d", &num);
    if(num>=0) {
      Insert(arr, 0, num);
    }
  }
  // print the tree in preorder, inorder, and postorder form;
  print_tree(arr);
  // free all memory used by the tree;
  free(arr);
  return 0;
}
