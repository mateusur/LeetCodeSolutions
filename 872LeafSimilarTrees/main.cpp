#include <iostream>
#include <vector>

using std::cout;
using std::endl;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inOrderTraversal(TreeNode *root1, std::vector<int> &v)
{
  if (root1->left) { inOrderTraversal(root1->left, v); }
  if (root1->right) { inOrderTraversal(root1->right, v); }
  if (!root1->left && !root1->right) { v.emplace_back(root1->val); }
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
  std::vector<int> v1, v2;
  inOrderTraversal(root1, v1);
  inOrderTraversal(root2, v2);
  if (v1.size() != v2.size()) { return false; }

  return v1 == v2;
}

int main()
{
  TreeNode t3(3);
  TreeNode t5(5);
  TreeNode t1(1);
  TreeNode t6(6);
  TreeNode t2(2);
  TreeNode t7(7);
  TreeNode t4(4);
  TreeNode t9(9);
  TreeNode t8(8);

  t3.left = &t5;
  t3.right = &t1;

  t5.left = &t6;
  t5.right = &t2;

  t2.left = &t7;
  t2.right = &t4;

  t1.left = &t9;
  t1.right = &t8;
  std::vector<int> v;
  inOrderTraversal(&t3, v);
  return 0;
}