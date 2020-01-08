

#include <iostream>
#include <vector>

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp_path;

        if(!root)
        	return res;
        if(!root->left && !root->right && root->val!=sum)
        	return res;
        if(!root->left && !root->right && root->val==sum){
        	res.push_back({root->val});
        	return res;
        }

        finder(root,0,sum,tmp_path,res);

        return res;

    }

    void finder(TreeNode *root, int tmp_sum, int sum,vector<int> tmp_path, vector<vector<int>> &path){
    	if(!root) return;
    	if(!root->left && !root->right && tmp_sum+root->val==sum){
    		tmp_path.push_back(root->val);
    		path.push_back(tmp_path);
    		tmp_path.pop_back();
    	}

    	if(!root->left && !root->right && tmp_sum+root->val!=sum)
    		tmp_path.pop_back();
    	if(root->left || root->right)
    		tmp_path.push_back(root->val);

    	finder(root->left,tmp_sum+root->val,sum,tmp_path,path);
    	finder(root->right,tmp_sum+root->val,sum,tmp_path,path);
    		
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}