

#include <iostream>
#include <stack>

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
    int maxAncestorDiff(TreeNode* root) {
		
		int maximum_diff = 0;
		if(!root) return maximum_diff;

		stack<TreeNode*> node_stack;
		node_stack.push(root);
		TreeNode* tmp_node;

		while(!node_stack.empty()){
			tmp_node = node_stack.top();
			node_stack.pop();

			DFS(tmp_node,tmp_node,maximum_diff);

			if(tmp_node->left)
				node_stack.push(tmp_node->left);
			if(tmp_node->right)
				node_stack.push(tmp_node->right);


		}

		return maximum_diff;

    }

    void DFS(const TreeNode *std_node,TreeNode *root, int &maximum_diff){
    	if(!root) return;

    	maximum_diff = max(abs(std_node->val-root->val),maximum_diff);

    	DFS(std_node,root->left,maximum_diff);
    	DFS(std_node,root->right,maximum_diff);
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}