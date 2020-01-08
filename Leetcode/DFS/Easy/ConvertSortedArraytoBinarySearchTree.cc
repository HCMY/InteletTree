


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums,0,nums.size()-1);
    }

    TreeNode *build_tree(vector<int> nums, int left,int right){
    	if(left>right) return NULL;

    	int mid_idx = (left+right)/2;
    	TreeNode *new_node = new TreeNode(nums[mid_idx]);
    	
    	new_node->left = build_tree(nums,left,mid_idx-1);
    	new_node->right = build_tree(nums,mid_idx+1,right);
        
        return new_node;
    }
};


int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}