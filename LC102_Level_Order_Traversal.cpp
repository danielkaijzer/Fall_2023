/*
Given the root of a binary tree,
return the level order traversal
of its nodes' values.
(i.e., from left to right, level by level)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> output; // 2D vector containing values in level order

        if (root == nullptr){
            return output; // return empty 2D vector if tree empty
        }

        queue<TreeNode*> level_queue; // queue for BFS
        level_queue.push(root);

        // BFS
        while (!level_queue.size() == 0){
            int n = level_queue.size(); // for iterative loop

            // initialize a vector to store all values at current level
            vector<int> level_vector;

            // iterate through all nodes at current level
            for (int i = 0; i <n; ++i){

                // now we'll use current node
                // to check for children
                // and then add it to our current level_vector
                auto curr_node = level_queue.front();

                // push nodes at next level into queue
                // (if there are nodes there)
                if (curr_node->left != nullptr){
                    level_queue.push(curr_node->left);
                }
                if (curr_node->right != nullptr){
                    level_queue.push(curr_node->right);
                }
                // add current node from current level to current level_vector
                level_vector.push_back(curr_node->val);
                // pop current node from current level from queue
                level_queue.pop();
            }

            // after all nodes at current level added to current level_vector
            // add level_vector to 2D vector output
            output.push_back(level_vector);
        }

        return output;
    }
};
