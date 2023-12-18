#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q){ // if both null we have reached leaves, so can backtrack
            return true;
        }
        // if only one is null, trees aren't same
        if (!p || !q){
            return false;
        }
        // if values don't match, trees aren't same
        if (p->val != q->val){
            return false;
        }
        // recursively compare left and right children
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};

int main(){
  // Create two identical trees
  TreeNode* tree1 = new TreeNode(1);
  tree1->left = new TreeNode(2);
  tree1->right = new TreeNode(3);
  tree1->left->left = new TreeNode(4);
  tree1->left->right = new TreeNode(5);
  tree1->right->left = new TreeNode(6);
  tree1->right->right = new TreeNode(6);

  TreeNode* tree2 = new TreeNode(1);
  tree2->left = new TreeNode(2);
  tree2->right = new TreeNode(3);
  tree2->left->left = new TreeNode(4);
  tree2->left->right = new TreeNode(5);
  tree2->right->left = new TreeNode(6);
  tree2->right->right = new TreeNode(7);

  // Test if the trees are identical
  Solution sol;
  if (sol.isSameTree(tree1, tree2)) {
    std::cout << "The trees are identical!" << std::endl;
  } else {
    std::cout << "The trees are not identical." << std::endl;
  }

  // Free the allocated memory
  delete tree1;
  delete tree2;

  return 0;
}