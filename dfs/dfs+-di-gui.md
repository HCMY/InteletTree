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

### Keys and Rooms

There are `N` rooms and you start in room `0`.  Each room has a distinct number in `0, 1, 2, ..., N-1`, and each room may have some keys to access the next room. Formally, each room `i` has a list of keys `rooms[i]`, and each key `rooms[i][j]` is an integer in `[0, 1, ..., N-1]` where `N = rooms.length`.  A key `rooms[i][j] = v` opens the room with number `v`.Initially, all the rooms start locked \(except for room `0`\). You can walk back and forth between rooms freely. Return `true` if and only if you can enter every room.

**Example 1:**

```text
Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
```

思路：DFS+递归遍历，同时记录下访问了的room,最后看是否还有room没有被访问到

```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    	if(rooms.size()<=1)
    		return true;
        vector<bool> visited(rooms.size(),false);
        DFS(rooms,visited,0);
        for(auto item:visited)
        	if(item==false)
        		return false;
        return true;
    }

    void DFS(const vector<vector<int>> rooms, vector<bool> &visited,int visited_room){
    	visited[visited_room] = true;
    	for(auto next_room:rooms[visited_room]){
    		if(!visited[next_room])
    			DFS(rooms,visited,next_room);
    	}
    }
};
```

### Delete Nodes And Return Forest

Given the `root` of a binary tree, each node in the tree has a distinct value.  
After deleting all nodes with a value in `to_delete`, we are left with a forest \(a disjoint union of trees\).   
Return the roots of the trees in the remaining forest.  You may return the result in any order.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/07/01/screen-shot-2019-07-01-at-53836-pm.png)

```text
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
```

思路：  
1. 先记录下 父节点，以及其左右孩子  
2. 如果父节点要被del，那么父节点赋为NULL，同时如果它的孩子不用被del，那么自然加入res  
3. 如果孩子需要被del，那么赋值为NULL  
4. 都不是，什么也不做

```cpp
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       vector<TreeNode*> res;
       //unordered_set<int> to_del(to_delete.begin(), to_delete.end());
        
        if(!root)
        	return res;
        
        DFS(root,NULL,res,to_delete);

        return res;
    }

    void DFS(TreeNode *&root, TreeNode *parent, vector<TreeNode*> &res, const vector<int> to_delete){
    	if(!root) return;

    	TreeNode *&left = root->left;
    	TreeNode *&right = root->right;

    	if(!is_todelete(root,to_delete) && !parent)
    		res.push_back(root);
    	else if(is_todelete(root,to_delete))
    		root = nullptr;

    	DFS(left,root,res,to_delete);
    	DFS(right,root,res,to_delete);

    }
```



