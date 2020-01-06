# BFS-Other

### 01 Matrix

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell. The distance between two adjacent cells is 1.

**Example 1:**

```text
Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
```

**Example 2:**

```text
Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
```

寻找离0最近的1，并把矩阵重新标记为它们之间的距离。

思路:把0元素位置全部入队，然后非0元素全部标记为MAX。然后pop队列，寻找队首元素（x）的四个方向，如果方向上的值 小于等于x+1的话（证明这个方向上的值是0），不做任何操作。反之，把这个方向上的值赋值为 x+1，并把这个值的位置入队。这样相当于对每个pop出来的位置，进行小范围的BFS

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
      queue<vector<int>> nodes_queue;
      vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};//four directions
      int rows = matrix.size();
      int cols = matrix[0].size();

      vector<int> tmp_node;


      // redefine matrix
      for(int i=0;i<rows;i++){
      	for(int j=0;j<cols;j++){
      		if(matrix[i][j]!=0)
      			matrix[i][j] = INT_MAX;
      		else if(matrix[i][j]==0)
      			nodes_queue.push({i,j}); 
      	}
      }

      while(!nodes_queue.empty()){
      	tmp_node = nodes_queue.front();
      	int x = tmp_node[0];
      	int y = tmp_node[1];

      	for(auto item:directions){
      		int curr_x = x+item[0];
      		int curr_y = y+item[1];
      		if((curr_x<0 || curr_x>=rows || curr_y<0 || curr_y>=cols) || matrix[curr_x][curr_y]<=(matrix[x][y]+1))
      			continue;
      		matrix[curr_x][curr_y]=matrix[x][y]+1;
      		nodes_queue.push({curr_x,curr_y});
      	}
      	nodes_queue.pop();
      }

      return matrix;

    }
};
```



