


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
    bool isBalanced(TreeNode* root) {
       if(!root) return true;
       if (abs(DFS(root->left)-DFS(root->right))>1) return false;

       return isBalanced(root->left) && isBalanced(root->right); 
       
    }

    int DFS(TreeNode *root){
    	if(!root) return 0;
    	return 1+max(DFS(root->left),DFS(root->right));
    }

};


int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}