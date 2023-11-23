#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void getInorderTraversalUtil(TreeNode *root, vector<int> &traversal) {
    if (root == nullptr) {
      return;
    }
    getInorderTraversalUtil(root->left, traversal);
    traversal.push_back(root->val);
    getInorderTraversalUtil(root->right, traversal);
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> anwser;
    getInorderTraversalUtil(root, anwser);
    return anwser;
}
int main() {
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3); 
  n1.right = &n2;
  n2.left = &n3;
  inorderTraversal(&n1);
}