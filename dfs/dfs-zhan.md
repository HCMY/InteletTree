# DFS-栈

递归需要消耗额外的资源，这些资源是：

1.递归由于是函数调用自身，而函数调用是有时间和空间的消耗的：每一次函数调用，都需要在内存栈中分配空间以保存参数、返回地址以及临时变量，而往栈中压入数据和弹出数据都需要时间 

2.递归中很多计算都是重复的，由于其本质是把一个问题分解成两个或者多个小问题，多个小问题存在相互重叠的部分，则存在重复计算，如fibonacci斐波那契数列的递归实现。-&gt;效率

3.调用栈可能会溢出，其实每一次函数调用会在内存栈中分配空间，而每个进程的栈的容量是有限的，当调用的层次太多时，就会超出栈的容量，从而导致栈溢出。-&gt;性能

## DFS-Stack 步骤

> init stack  
> stack.push\(root\)  
> visited\(root\)=true  
>   
> while\(stack.empty\(\)\):  
>     get top node  
>     stack.pop\(\)  
>     for\(n in node's neighbors\):  
>         if\(!visited\(n\)\):  
>             stack.push\(n\)  
>             visited\[n\]=true

> 总体而言，点入栈方式看起来类似与BFS，但实际上，因为每次都是访问的栈顶元素，根据栈顶元素访问其邻居节点，岁所有，实际上元素的访问顺序是DFS，也就是先一条路走到黑，走不通之后pop掉一个点，接着访问栈顶元素的未被访问到的节点

### Deepest Leaves Sum

Given a binary tree, return the sum of values of its deepest leaves.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png)

```text
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
```

这道题使用了递归和非递归2种方案，记录下叶子节点的值及其深度，最后再统一计算和  


```cpp
//递归
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> max_depth_leaf;
        int sum = 0;
        if(!root)
        	return sum;

        DFS(root,1,max_depth_leaf);
        
        int max_depth = 0;
        for(auto item:max_depth_leaf)
        	max_depth = max(item[0],max_depth);
        for(auto item:max_depth_leaf){
        	if(item[0]==max_depth)
        		sum += item[1];
        }

        return sum;
    }

    void DFS(TreeNode *root,int depth,vector<vector<int>> &max_depth_leaf){
    	if(!root) return;
    	if(!root->left && !root->right)
    		max_depth_leaf.push_back({depth,root->val});
    	
    	DFS(root->left,depth+1,max_depth_leaf);
    	DFS(root->right,depth+1,max_depth_leaf);
    }
};


//非递归
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
    	stack<pair<TreeNode*,int>> my_stack;
    	vector<vector<int>> max_depth_leaf;
    	int sum = 0;
    	
    	if(!root)
    		return sum;

    	pair<TreeNode*,int> one_pair(root,1);

    	my_stack.push(one_pair);

    	TreeNode *tmp_node;
    	int depth = 0;

    	while(!my_stack.empty()){
    		one_pair = my_stack.top();
    		tmp_node = one_pair.first;
    		depth = one_pair.second;
    		my_stack.pop();

    		if(!tmp_node->left && !tmp_node->right)
    			max_depth_leaf.push_back({depth,tmp_node->val});

    		if(tmp_node->left){
    			one_pair.first = tmp_node->left;
    			one_pair.second = depth+1;
    			my_stack.push(one_pair);
    		}
    		
    		if(tmp_node->right){
    			one_pair.first = tmp_node->right;
    			one_pair.second = depth+1;
    			my_stack.push(one_pair);
    		}
    	}

    	int max_depth = 0;
        for(auto item:max_depth_leaf)
        	max_depth = max(item[0],max_depth);
        for(auto item:max_depth_leaf){
        	if(item[0]==max_depth)
        		sum += item[1];
        }

        return sum;
    }

  };

```

