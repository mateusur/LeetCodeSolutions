#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int recursion(TreeNode *node, int counter) {
  if (node) {
    counter++;
    int l = recursion(node->left, counter);
    int r = recursion(node->right, counter);
    return l > r ? l : r;
  }
  return counter;
}

int maxDepth(TreeNode *root) {
  int counter = 0;
  return recursion(root, counter);
}

int main() {}