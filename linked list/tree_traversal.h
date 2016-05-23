typedef struct node {
  int number;
  struct node *left;
  struct node *right;
} Node;

Node *create_node(void);
void set_number(Node *n, int num);
Node *Insert(Node *root, int num);
void Preorder(Node *root);
void Inorder(Node *root);
void Postorder(Node *root);
void print_tree(Node *root);
