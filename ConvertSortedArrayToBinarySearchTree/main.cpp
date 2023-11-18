#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

TreeNode* createTree(vector<int>& nums,size_t min,size_t max){
  if(max+1-min<1)
    return nullptr;
  else{
     size_t mid = (min+max)/2;
     int nodeNum = nums.at(mid);
    TreeNode* node = new TreeNode(nodeNum);
    node->left = createTree(nums,min,mid-1);
    node->right = createTree(nums,mid+1,max);
    return node;
  }
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
  size_t size = nums.size();
  if(size==1){
    TreeNode* node = new TreeNode(nums.at(0));
    return node;
  }
  TreeNode* root = createTree(nums,0,size-1);
  return root;
}

int main() {
vector<int> num={-10,-3,0,5,9};
sortedArrayToBST(num);
}