


/**
 * Definition for a binary tree nodestruct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> my_queue;
        vector<int> res;

        if(!root)
        	return res;

        my_queue.push(root);
        my_queue.push(NULL);

        
        TreeNode *tmp_node;

        while(!my_queue.empty()){
        	int _max = INT_MIN;
        	while(my_queue.front()!=NULL){
        		tmp_node = my_queue.front();
        		_max = max(tmp_node->val,_max);

        		if(tmp_node->left)
        			my_queue.push(tmp_node->left);
        		if(tmp_node->right)
        			my_queue.push(tmp_node->right);

        		my_queue.pop();
        	}
        	my_queue.pop();
        	if(!my_queue.empty())
        		my_queue.push(NULL);

        	res.push_back(_max);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}