#include <stdio.h>
#include "tree_traversal.h"

void Preorder(int *arr, int index)
{
  // if root node is empty;
  if(arr[index] == -1) {
    // Then do nothing;
    return ;
  }
  // print the root node of tree;
  printf("%d ", arr[index]);
  // recursive function to the left branch in tree;
  Preorder(arr, index*2 + 1);
  // recursive function to the right branch in tree;
  Preorder(arr, index*2 + 2);
}

void Inorder(int *arr, int index)
{
  if(arr[index] == -1) {
    return ;
  }
  Inorder(arr, index*2 + 1);
  printf("%d ", arr[index]);
  Inorder(arr, index*2 + 2);
}

void Postorder(int *arr, int index)
{
  if(arr[index] == -1) {
    return ;
  }
  Postorder(arr, index*2 + 1);
  Postorder(arr, index*2 + 2);
  printf("%d ", arr[index]);
}

// to insert a new entry in an array stored as a binary tree;
void Insert(int *arr, int index, int num)
{
  // if root node is empty;
  if(arr[0] == -1) {
    // Then set the root node to a new leaf containing new value;
    arr[0] = num;
  }
  else {
    // if new value == value of root node;
    if(num == arr[index]) {
      printf("This is a duplicate key and will be ignored.\n");
    }
    else if(num < arr[index]) {
      // if left child node of root node is empty;
      if(arr[index*2+1] == -1) {
        // Then set the node to a new leaf containing new value;
        arr[index*2+1] = num;
      }
      else {
        //to insert new value into subtree identified by the left child node;
        Insert(arr, index*2+1, num);
      }
    }
    else if(num > arr[index]) {
      // if right child node of root node is empty;
      if(arr[index*2+2] == -1) {
        arr[index*2+2] = num;
      }
      else {
        //to insert new value into subtree identified by the right child node;
        Insert(arr, index*2+2, num);
      }
    }
  }
}

// print the tree in preorder, inorder, and postorder form;
void print_tree(int *arr)
{
  printf("Preorder: ");
  Preorder(arr, 0);
  puts("");
  printf("Inorder: ");
  Inorder(arr, 0);
  puts("");
  printf("Postorder: ");
  Postorder(arr, 0);
  puts("");
}
