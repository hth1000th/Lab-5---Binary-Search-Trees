#include <stdio.h>
#include <stdlib.h>
#include "tree_traversal.h"

// to create empty node; set its left & right nodes to empty;
Node *create_node(void)
{
  Node *n = (Node*)malloc(sizeof(Node));
  n->left = NULL;
  n->right = NULL;
  return n;
}

// to assign new value to the root node;
void set_number(Node *n, int num)
{
  n->number = num;
}

// to insert a new entry in a list stored as a binary tree;
Node *Insert(Node *root, int num)
{
  // if root node is empty;
  if(root == NULL) {
    // Then set the root node to a new leaf containing new value;
    root = create_node();
    set_number(root, num);
  }
  else {
    // if new value == value of root node;
    if(num == root->number) {
      printf("This is a duplicate key and will be ignored.\n");
    }
    else if(num < root->number) {
      // if left child node of root node is empty;
      if(root->left == NULL) {
        // Then set the node to a new leaf containing new value;
        root->left = create_node();
        set_number(root->left, num);
      }
      else {
        //to insert new value into subtree identified by the left child node;
        root->left = Insert(root->left, num);
      }
    }
    else if(num > root->number) {
      // if right child node of root node is empty;
      if(root->right == NULL) {
        root->right = create_node();
        set_number(root->right, num);
      }
      else {
        //to insert new value into subtree identified by the right child node;
        root->right = Insert(root->right, num);
      }
    }
  }
  return root;
}

void Preorder(Node *root)
{
  // if root node is empty;
  if(root == NULL) {
    // Then do nothing;
    return ;
  }
  // print the root node of tree;
  printf("%d ", root->number);
  // recursive function to the left branch in tree;
  Preorder(root->left);
  // recursive function to the right branch in tree;
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

// print the tree in preorder, inorder, and postorder form;
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
