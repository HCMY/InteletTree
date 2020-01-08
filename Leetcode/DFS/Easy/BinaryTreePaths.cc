

#include <iostream>
#include <vector>
#include <string>

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
    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		
		DFS(root,res,"");
		return res;
		
    }

    void DFS(TreeNode *root, vector<string> &seq, string path){
    	if(!root) return;
    	if(!root->left && !root->right){
    		seq.push_back(path+to_string(root->val));
    		path = "";
    	}

    	DFS(root->left, seq, path+to_string(root->val)+"->");
    	DFS(root->right,seq,path+to_string(root->val)+"->");
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}