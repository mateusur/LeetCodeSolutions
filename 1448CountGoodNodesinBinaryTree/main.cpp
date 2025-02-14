#include <stdint.h>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inOrderTraversal(TreeNode *root1, int current_max, int &good)
{
  if (root1->val > current_max) {
    ++good;
    current_max = root1->val;
  }
  if (root1->left) { inOrderTraversal(root1->left, current_max, good); }
  if (root1->right) { inOrderTraversal(root1->right, current_max, good); }
}

int goodNodes(TreeNode *root)
{
  int good = 0;
  int current_max = INT32_MIN;
  inOrderTraversal(root, current_max, good);

  return good;
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
  goodNodes(&t3);
  return 0;
}
