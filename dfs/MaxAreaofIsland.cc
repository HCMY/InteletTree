
/**
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int maxArea = 0, curArea = 1;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1) {
                    findMaxArea(grid, i, j, curArea);
                    maxArea = max(maxArea, curArea);
                    curArea = 1;
                }
        
        return maxArea;
    }

private:
    vector<int> rows = {1, -1, 0, 0};
    vector<int> cols = {0, 0, 1, -1};
    void findMaxArea(vector<vector<int>>& grid, int i, int j, int& curArea) {
        grid[i][j] = 0;
        for (int m = 0; m < 4; m++) {
            int row = i + rows[m], col = j + cols[m];
            if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) continue;
            
            if (grid[row][col] == 1) findMaxArea(grid, row, col, ++curArea);
        }
    }
};
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	
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

int main(int argc, char const *argv[])
{
	Solution solu;
	return 0;
}


