#include <stdio.h>
#include "tree_traversal.h"

void Preorder(int *arr, int index)
{
    if(arr[index] == -1) {
      return ;
    }
    printf("%d ", arr[index]);
    Preorder(arr, index*2 + 1);
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

void Insert(int *arr, int index, int num)
{
  if(arr[0] == -1) {
    arr[0] = num;
  }
  else {
    if(num == arr[index]) {
      printf("This is a duplicate key and will be ignored.\n");
    }
    else if(num < arr[index]) {
      if(arr[index*2+1] == -1) {
        arr[index*2+1] = num;
      }
      else {
        Insert(arr, index*2+1, num);
      }
    }
    else if(num > arr[index]) {
      if(arr[index*2+2] == -1) {
        arr[index*2+2] = num;
      }
      else {
        Insert(arr, index*2+2, num);
      }
    }
  }
}

void print_tree(int *arr)
{
  printf("Preorder: ");
  Preorder(arr, 0);
  printf("\n");
  printf("Inorder: ");
  Inorder(arr, 0);
  printf("\n");
  printf("Postorder: ");
  Postorder(arr, 0);
  printf("\n");
}
