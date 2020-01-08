

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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> max_depth_leaf;
        int sum = 0;
        if(!root)
        	return sum;

        DFS(root,1,max_depth_leaf);
        
        int max_depth = 0;
        for(auto item:max_depth_leaf)
        	max_depth = max(item[0],max_depth);
        for(auto item:max_depth_leaf){
        	if(item[0]==max_depth)
        		sum += item[1];
        }

        return sum;
    }

    void DFS(TreeNode *root,int depth,vector<vector<int>> &max_depth_leaf){
    	if(!root) return;
    	if(!root->left && !root->right)
    		max_depth_leaf.push_back({depth,root->val});
    	
    	DFS(root->left,depth+1,max_depth_leaf);
    	DFS(root->right,depth+1,max_depth_leaf);
    }
};


int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}