#include <stdio.h>
#include <stdlib.h>
#include "tree_traversal.h"

Node *create_node(void)
{
  Node *n = (Node*)malloc(sizeof(Node));
  n->left = NULL;
  n->right = NULL;
  return n;
}

void set_number(Node *n, int num)
{
  n->number = num;
}

// to insert a new entry in a list stored as a binary tree;
Node *Insert(Node *root, int num)
{
  if(root == NULL) {
    root = create_node();
    set_number(root, num);
  }
  else {
    if(num == root->number) {
      printf("This is a duplicate key and will be ignored.\n");
    }
    else if(num < root->number) {
      if(root->left == NULL) {
        root->left = create_node();
        set_number(root->left, num);
      }
      else {
        root->left = Insert(root->left, num);
      }
    }
    else if(num > root->number) {
      if(root->right == NULL) {
        root->right = create_node();
        set_number(root->right, num);
      }
      else {
        root->right = Insert(root->right, num);
      }
    }
  }
  return root;
}

void Preorder(Node *root)
{
  if(root == NULL) {
    return ;
  }
  printf("%d ", root->number);
  Preorder(root->left);
  Preorder(root->right);
}

void Inorder(Node *root)
{
  if(root == NULL) {
    return ;
  }
  Inorder(root->left);
  printf("%d ", root->number);
  Inorder(root->right);
}

void Postorder(Node *root)
{
  if(root == NULL) {
    return ;
  }
  Postorder(root->left);
  Postorder(root->right);
  printf("%d ", root->number);
}

void print_tree(Node *root)
{
  printf("Preorder: ");
  Preorder(root);
  puts("");
  printf("Inorder: ");
  Inorder(root);
  puts("");
  printf("Postorder: ");
  Postorder(root);
  puts("");
}
