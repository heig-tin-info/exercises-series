

typedef struct node {
  unsigned int value;
  struct node *left;
  struct node *right;
} Node;


int search(Node *root, unsigned int value) {
  if (root == NULL) {
    return 0;
  }
  if (root->value == value) {
    return 1;
  }
  if (root->value > value) {
    return search(root->left, value);
  }
  return search(root->right, value);
}