/**
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.


*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
class Solution {
private:
	struct orange{
		int row,col;
		orange(int x,int y){
			row=x;
			col=y;
			}
	};

public:
	bool is_valid(int row,int col, const int rows, const int cols){
		if(row>=0 && row<rows && col>=0 && col<cols)
			return true;
		return false;
	}

	bool is_round_node(orange node){
		if(node.row==-1 && node.col==-1)
			return true;
		return false;
	}

	bool is_fresh(int value){
		return value==1;
	}

	bool all_rotting(vector<vector<int>>& grid){
		int rows = grid.size();
		int cols = grid[0].size();
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(grid[i][j]==1)
					return false;
			}
		}
		return true;
	}


    int orangesRotting(vector<vector<int>>& grid) {
		int rows = grid.size();
		int cols = grid[0].size();

		queue<orange> Q;
		int minimum_minite=0;
		orange temp(0,0);

		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(grid[i][j]==2){
					orange node(i,j);
					Q.push(node);
				}
			}
		}
		
		orange round_node(-1,-1);
		Q.push(round_node);

		while(!Q.empty()){
			bool round_finish = false;

			while(!is_round_node(Q.front())){
				temp = Q.front();
				if(is_valid(temp.row,temp.col+1,rows,cols) && (is_fresh(grid[temp.row][temp.col+1]))){
					if(!round_finish){minimum_minite++;round_finish=true;}
					grid[temp.row][temp.col+1] = 2;
					temp.col++;
					Q.push(temp);
					temp.col--;
				}
				//check left site
				if(is_valid(temp.row,temp.col-1,rows,cols) && (is_fresh(grid[temp.row][temp.col-1]))){
					if(!round_finish){minimum_minite++;round_finish=true;}
					grid[temp.row][temp.col-1] = 2;
					temp.col--;
					Q.push(temp);
					temp.col++;
				}

				//check up
				if(is_valid(temp.row-1,temp.col,rows,cols) && is_fresh(grid[temp.row-1][temp.col])){
					if(!round_finish){minimum_minite++;round_finish=true;}
					grid[temp.row-1][temp.col] = 2;
					temp.row--;
					Q.push(temp);
					temp.row++;
				}
				//check down
				if(is_valid(temp.row+1,temp.col,rows,cols) && is_fresh(grid[temp.row+1][temp.col])){
					if(!round_finish){minimum_minite++;round_finish=true;}
					grid[temp.row+1][temp.col] = 2;
					temp.row++;
					Q.push(temp);
					temp.row--;
				}
				Q.pop();

			}
			Q.pop();

			if(!Q.empty()){
				temp.row = -1;
				temp.col = -1;
				Q.push(temp);
			}
		}

		return all_rotting(grid) ? minimum_minite:-1;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;

	vector<vector<int>> arr1 = {{2,1,1},{1,1,0},{0,1,1}};
	vector<vector<int>> arr2 = {{2,1,1},{0,1,1},{1,0,1}};

	cout<<solu.orangesRotting(arr1)<<endl;
	cout<<solu.orangesRotting(arr2)<<endl;


	return 0;
}

