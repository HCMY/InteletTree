

#include <iostream>
#include <climits>

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
    int minDepth(TreeNode* root) {
        int min_depth = INT_MAX;
        if(!root)
        	return 0;
        DFS(root,1,min_depth);
        return min_depth;

    }

    void DFS(TreeNode *root, int depth, int &min_depth){
    	if(!root) return;
    	if(!root->left && !root->right)
    		min_depth = min(depth,min_depth);

    	DFS(root->left,depth+1,min_depth);
    	DFS(root->right,depth+1,min_depth);
    }
};


int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}