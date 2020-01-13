---
description: >-
  这类问题一般给一个矩阵，要求矩阵内满足条件的一些元素。这类问题的一般做法是：先遍历整个矩阵，并找到要DFS的位置/元素，
  把他们push入栈，然后对栈内元素进行DFS。当然，也可以用递归实现整个思路
---

# DFS-矩阵类

### Max Area of Island

Given a non-empty 2D array `grid` of 0's and 1's, an **island** is a group of `1`'s \(representing land\) connected 4-directionally \(horizontal or vertical.\) You may assume all four edges of the grid are surrounded by water. Find the maximum area of an island in the given 2D array. \(If there is no island, the maximum area is 0.\)

**Example 1:**

```text
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
```

Given the above grid, return `6`. Note the answer is not 11, because the island must be connected 4-directionally.

**Example 2:**

```text
[[0,0,0,0,0,0,0,0]]
```

思路：遍历整个矩阵，对元素为1的位置进行DFS，此时只有四个方向上的DFS：上下左右，当访问到边界的时候，退回。注意，访问过的位置，元素值可以直接赋值为0，因为0我们是不进行DFS的，可以当作visited

```cpp
public:
	vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    		if (grid.empty() || grid[0].empty()) return 0;
    		
    		int max_area = 0;
    		int tmp_area = 1;

    		int rows = grid.size();
    		int cols = grid[0].size();

    		for(int i=0;i<rows;i++){
    			for(int j=0;j<cols;j++){
    				if(grid[i][j]==1){
    					DFS(grid,i,j,tmp_area);
    					max_area = max(max_area,tmp_area);
    					tmp_area = 1;
    				}
    			}
    		}

    		return max_area;
    	}

    void DFS(vector<vector<int>> &grid, int x, int y,int &tmp_area){
    	grid[x][y] = 0;//mean visited
    	for(auto direc:directions){
    		int next_x = x+direc[0];
    		int next_y = y+direc[1];
    		if(next_x<0||next_x>=grid.size()||next_y<0||next_y>=grid[0].size())
    			continue;
    		if(grid[next_x][next_y]==1){
    			tmp_area++;
    			DFS(grid,next_x,next_y,tmp_area);
    		}
    	}
    }
};
```



