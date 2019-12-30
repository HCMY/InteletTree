


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
    int findBottomLeftValue(TreeNode* root) {
        int last_val;
        TreeNode *tmp_node;
        vector<int> tmp_vec;
        if(!root)
        	return last_val;
        
        queue<TreeNode*> my_queue;
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

        	last_val = tmp_vec[0];
        	tmp_vec.clear();

        }

        return last_val;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}