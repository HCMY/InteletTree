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
    vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> my_queue;
		vector<vector<int>> res;
		vector<int> tmp_res;
		TreeNode *tmp;

		if(!root)
			return res;
		
		my_queue.push(root);
		my_queue.push(NULL);

		while(!my_queue.empty()){
			while(my_queue.front()!=NULL){
				tmp = my_queue.front();
				tmp_res.push_back(tmp->val);
				if(tmp->left)
					my_queue.push(tmp->left);
				if(tmp->right)
					my_queue.push(tmp->right);
				my_queue.pop();
			}
			my_queue.pop();
			if(!my_queue.empty())
				my_queue.push(NULL);
			res.push_back(tmp_res);
			tmp_res.clear();
		}

		return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}