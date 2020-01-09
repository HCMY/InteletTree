

#include <iostream>

using namespace std;

 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
    int moves;
    
    int distribute(TreeNode *root){
        if(!root){
            return 0;
        }
        
        int l = distribute(root->left);
        int r = distribute(root->right);
        moves += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        moves = 0;
        distribute(root);
        return moves;
    }
};
