#include <stdio.h>
#include <stdlib.h>
#include "tree_traversal.h"

int main(void)
{
  int num = 0;
  Node *root = NULL;

  while(num >= 0) {
    printf("Enter the integer (Negative number to stop): ");
    scanf("%d", &num);
    if(num >= 0) {
      root = Insert(root, num);
    }
  }
  // print the tree in preorder, inorder, and postorder form;
  print_tree(root);
  // free all memory used by the tree;
  free(root);
  
  return 0;
}
