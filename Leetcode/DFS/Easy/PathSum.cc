

#include <istream>

using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	 if(!root)
    	 	return false;
    	 return finder(root,0,sum);

    }

    bool finder(TreeNode *root, int tmp_sum, int sum){
    	if(!root) return false;
    	if(!root->left && !root->right && tmp_sum+root->val==sum)
    		return true;

    	return finder(root->left,tmp_sum+root->val,sum)||finder(root->right,tmp_sum+root->val,sum);
    }
};


int main(int argc, char const *argv[])
{
	Solution solu;

	return 0;
}