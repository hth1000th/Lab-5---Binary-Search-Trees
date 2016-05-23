#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "tree_traversal.h"
#include <test_bst.h>

int main(void) {

  test_create_node();
  test_set_number();
  test_Insert();
  test_Preorder();
  test_Inorder();
  test_Postorder();
  test_print_tree();

  puts("");
  puts("TESTING COMPLETE!");
  return 0;
}

void test_create_node() {
  puts("testing Node *create_node(void)");
  Node *node = create_node();
  assert(node->number == 0);
  assert(node->left == NULL);
  assert(node->right == NULL);
  free(node);
}

void test_set_number() {
  puts("testing void set_number(Node *n, int num)");
  Node *node = create_node();
  set_number(node, 12);
  assert(node->number == 12);
  set_number(node, 0);
  assert(node->number == 0);
  set_number(node, -384);
  assert(node->number -384);
  free(node);
}

void test_Insert() {
  puts("testing Node *Insert(Node *root, int num)");
  Node *node = NULL;
  node = Insert(node, 7);
  assert(node->number == 7);
  node = Insert(node, 29);
  assert(node->right->number == 29);
  node = Insert(node, 0);
  assert(node->left->number == 0);
  node = Insert(node, -10);
  assert(node->left->left->number == -10);
  node = Insert(node, 14);
  assert(node->right->left->number == 14);
  free(node);
}

void test_Preorder() {
  puts("testing void Preorder(Node *root)");
  Node *node = NULL;
  node = Insert(node, 5);
  node = Insert(node, 4);
  node = Insert(node, 9);
  node = Insert(node, -2);
  node = Insert(node, 0);
  node = Insert(node, 8);
  Preorder(node);
  puts("");
  free(node);
}

void test_Inorder() {
  puts("testing void Inorder(Node *root)");
  Node *node = NULL;
  node = Insert(node, 5);
  node = Insert(node, 4);
  node = Insert(node, 9);
  node = Insert(node, -2);
  node = Insert(node, 0);
  node = Insert(node, 8);
  Inorder(node);
  puts("");
  free(node);
}

void test_Postorder() {
  puts("testing void Postorder(Node *root)");
  Node *node = NULL;
  node = Insert(node, 5);
  node = Insert(node, 4);
  node = Insert(node, 9);
  node = Insert(node, -2);
  node = Insert(node, 0);
  node = Insert(node, 8);
  Postorder(node);
  puts("");
  free(node);
}

void test_print_tree() {
  puts("testing void print_tree(Node *root)");
  Node *node = NULL;
  node = Insert(node, 23);
  node = Insert(node, 52);
  node = Insert(node, 3);
  node = Insert(node, -4);
  node = Insert(node, 0);
  node = Insert(node, 34);
  print_tree(node);
  free(node);
}
