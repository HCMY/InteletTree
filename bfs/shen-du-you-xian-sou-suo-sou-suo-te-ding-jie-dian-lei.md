---
description: BFS的思路和二叉树的层次遍历是一样的，BFS一般通过 队列 辅助存储结点信息得以实现。
---

# 深度优先搜索-搜索特定结点类

## _1._ N-ary Tree Level Order Traversal

Given an n-ary tree, return the level order traversal of its nodes' values.

_Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value \(See examples\)._

![Input: root = \[1,null,3,2,4,null,5,6\] Output: \[\[1\],\[3,2,4\],\[5,6\]\]](../.gitbook/assets/image.png)

题目的目的是把每一层的节点都存储在一个列表中，最后返回一个二维列表

**思路：用一个辅助队列，存储下每一层的节点，以及使用一个分割符号记录层结束时的节点，之后利用这个队列依次遍历即可**

## 2. Find Bottom Left Tree Value

Given a binary tree, find the leftmost value in the last row of the tree.

**Example 1:**

```text
Input:

    2
   / \
  1   3

Output:
1

```

```text
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
```

题意不用多说，也是同样的做法，队列辅助+分割符为主，记录下每一层最左边的数字，和下一题几乎一模一样

```cpp
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
        my_queue.push(NULL);//插入分割符
        while(!my_queue.empty()){
        	while(my_queue.front()!=NULL){//到达一个分割符，一层结束
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
```
```

## 3 Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the _right_ side of it, return the values of the nodes you can see ordered from top to bottom.

**Example:**

```text
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
 
```

这题稍微需要转个弯子：相当于记录下每一层的最右边的结点，这就相当于要得到每一层最后一个结点，如果某一层只有一个结点，那么就是其本身。**可以通过设定一个辅助数组，记录下该层的所有结点，最后一层遍历完，得到这个数组的最后一个元素就可以的得到结果。同样是使用 队列+分割符**

```cpp
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

    		res.push_back(tmp_vec[tmp_vec.size()-1]);
    		tmp_vec.clear();
    	}

    	return res;
 
    }
};
```
```

## 4. Find Largest Value in Each Tree Row

You need to find the largest value in each row of a binary tree.

**Example:**

```text
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
```

**队列+分割符，记录下每一层最大的元素就可以了,可以用 INT\_MIN 初始化，代表每一层最小的值**

```cpp
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
```
```



