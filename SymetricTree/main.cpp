#include <iostream>
#include <stack>

using std::stack;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

bool isMirrored(TreeNode *left, TreeNode *right) {
  if (left == nullptr && right == nullptr) {
    return true;
  }
  if (left != nullptr && right != nullptr && left->val == right->val) {
    return isMirrored(left->left, right->right) &&
           isMirrored(left->right, right->left);
  }
  return false;
}

bool iterative(TreeNode *root) {
  if (root == nullptr) {
    return true;
  }
  stack<TreeNode *> left;
  stack<TreeNode *> right;
  left.push(root->left);
  right.push(root->right);
  while (left.size() > 0) {
    TreeNode *l = left.top();
    left.pop();
    TreeNode *r = right.top();
    right.pop();
    if ((!l && r) || (l && !r)) {
      return false;
    }
    if (l && r) {
      if (l->val != r->val) {
        return false;
      }
      left.push(l->left);
      right.push(r->right);
      left.push(l->right);
      right.push(r->left);
    }
  }
  return true;
}

bool isSymmetric(TreeNode *root) {
  //  return isMirrored(root, root);
  return iterative(root);
}

int main() {}