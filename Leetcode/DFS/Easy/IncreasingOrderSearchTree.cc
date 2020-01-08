

//Definition for a binary tree node.
#include <iostream>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        return revise(root,nullptr);
        
    }

    TreeNode *revise(TreeNode *root,TreeNode* parent){
    	if(!root) return parent;

    	TreeNode *res = revise(root->left, root);
    	root->left = nullptr;
    	root->right = revise(root->right,parent);

    	return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}
