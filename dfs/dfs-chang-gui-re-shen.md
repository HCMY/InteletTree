# DFS-常规/热身

DFS一般的流程是这样的：从一个点出发，遍历其中一个邻居节点w, 然后接着遍历w的一个邻居节点，当遍历到最后一个节点之后，回退回上一个已经被遍历过的节点，接着遍历这个节点的未被遍历的节点，依次循环，直到遍历完所有的点为止。

### Maximum Depth of N-ary Tree

Given a n-ary tree, find its maximum depth.The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node._Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value \(See examples\)._

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```text
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```text
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5
```

比较常规，用递归实现DFS的思路

```cpp
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int max_depth = 1;
        DFS(root,1,max_depth);
        return max_depth;
    }

    void DFS(Node *node, int depth, int &max_depth){
        if(!node) return;
        if((node->children).empty())
            max_depth = max(depth,max_depth);

        for(auto tmp_node:node->children)
            DFS(tmp_node,depth+1,max_depth);
    }
};

```

### Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.**Note:** A leaf is a node with no children.

**Example:**

Given binary tree `[3,9,20,null,null,15,7]`,

```text
    3
   / \
  9  20
    /  \
   15   7
```

return its depth = 3.

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        DFS(root,1,max_depth);
        return max_depth;
    }

    void DFS(TreeNode *root, int depth, int &max_depth){
    	if(!root) return;
    	if(!root->left || root->right)
    		max_depth = max(depth,max_depth);

    	DFS(root->left,depth+1,max_depth);
    	DFS(root->right,depth+1,max_depth);
    }
};

```

### Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST. For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of _every_ node never differ by more than 1.

**Example:**

```text
Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
```

思路: 因为要构建的是BST，且我们的数组是递增的，刚好BST的中序遍历能得到有序的数组，这样一来我们可以根据二分查找的思想，递归的构建BST

```cpp
  
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
```

