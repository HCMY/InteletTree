/**

如:
1  2  3  4  5
6  7  8  9  10 
11 12 12 14 15
16 17 18 19 20

思路: 从上到下, 从右到左遍历
当 element>arr[row][col],证明元素比该行最大的还大,此时 row++
当 element<arr[row][col],证明元素就在这行上, col--

*/


class Solution {
public:
    bool Find(int target, vector<vector<int> > array){
        int row = 0;
        int col = array[0].size()-1;
        while(row<array.size() && col>=0){
        	if(array[row][col]==target)
        		return true;
        	else if(array[row][col]<target)
        		row++;
        	else
        		col--;
        }

        return false;
    }
};


// First train
/*
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row=0;
        int col = array[0].size()-1;
        while(row<array.size() && col>=0){
        	if(array[row][col]==target)
        		return true;
        	else if(array[row][col]<target)
        		row++;
        	else
        		col--;
        }

        return false;
    }
};*/
