
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
  		int count = 0;
  		func(1,1,n,m,count);
  		return count;
    }

    void func(int right, int down, int rows, int cols, int &count){
    	if(down==rows && right==cols)
    		count++;
    	if(down>rows || right>cols)
    		return;

    	if(right!=cols)
    		func(right+1,down,rows,cols,count);
    	if(down!=rows)
    		func(right,down+1, rows,cols,count);
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	cout<<solu.uniquePaths(3,2)<<endl;
	cout<<solu.uniquePaths(23,12)<<endl;
	return 0;
}