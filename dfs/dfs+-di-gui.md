---
description: 递归是实现DFS策略的经常性手段
---

# DFS+递归

### Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.**Note:** A leaf is a node with no children.

**Example:**

Given the below binary tree and `sum = 22`,

```text
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
```

Return:

```text
[
   [5,4,11,2],
   [5,8,4,5]
]
```

思路: 使用递归，使用一个数组，记录下遍历的路径，当遍历到叶子节点的时候，判断是否满足条件，如果不的话，数组pop掉最后一个，相当于这条路走不通，递归会相应的回退到上一个节点，继续寻找。

```cpp
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp_path;

        if(!root)
        	return res;
        if(!root->left && !root->right && root->val!=sum)
        	return res;
        if(!root->left && !root->right && root->val==sum){
        	res.push_back({root->val});
        	return res;
        }

        finder(root,0,sum,tmp_path,res);

        return res;

    }

    void finder(TreeNode *root, int tmp_sum, int sum,vector<int> tmp_path, vector<vector<int>> &path){
    	if(!root) return;
    	if(!root->left && !root->right && tmp_sum+root->val==sum){
    		tmp_path.push_back(root->val);
    		path.push_back(tmp_path);
    		tmp_path.pop_back();
    	}

    	if(!root->left && !root->right && tmp_sum+root->val!=sum)
    		tmp_path.pop_back();
    	if(root->left || root->right)
    		tmp_path.push_back(root->val);

    	finder(root->left,tmp_sum+root->val,sum,tmp_path,path);
    	finder(root->right,tmp_sum+root->val,sum,tmp_path,path);
    		
    }
};
```

