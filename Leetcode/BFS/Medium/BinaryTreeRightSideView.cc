/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> tmp_vec;
    	vector<int> res;
    	TreeNode *tmp_node;
    	queue<TreeNode*> my_queue;
    	if(!root)
    		return res;

    	my_queue.push(root);
    	my_queue.push(NULL);

    	while(!my_queue.empty()){
    		while(my_queue.front()!=NULL){
    			tmp_node = my_queue.front();
    			tmp_vec.push_back(tmp_node->val);
    			if(tmp_node->left)
    				my_queue.push(tmp_node->left);
    			if(tmp_node->right)
    				my_queue.push(tmp_node->right);

    			my_queue.pop();
    		}
    		my_queue.pop();
    		if(!my_queue.empty())
    			my_queue.push(NULL);

    		res.push_back(tmp_vec[-1]);
    		tmp_vec.clear();
    	}

    	return res;
 
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;

	return 0;
}