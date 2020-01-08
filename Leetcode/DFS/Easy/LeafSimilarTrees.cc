
#include <iostream>
#include <vector>

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> root1_leaf_seq;
		vector<int> root2_leaf_seq;

		DFS(root1,root1_leaf_seq);
		DFS(root2,root2_leaf_seq);

		if(root2_leaf_seq.size()!=root1_leaf_seq.size())
			return false;

		int size = root1_leaf_seq.size();
		for(int i=0;i<size;i++){
			if(root1_leaf_seq[i]!=root2_leaf_seq[i])
				return false;
		}

		return true;

    }

    void DFS(TreeNode *root, vector<int> &leaf_seq){
    	if(!root) return;
    	if(!root->left && !root->right)
    		leaf_seq.push_back(root->val);
    	DFS(root->left,leaf_seq);
    	DFS(root->right,leaf_seq);
    }
};



int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}