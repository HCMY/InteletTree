/**
题目是输入一个旋转好了的数组如:{3,4,5,1,2}
要求输出最小的元素:
1. 直接排序? 显然题目的意思并不是这样, 虽然这样也能做, 但有可能会导致时间不足
2.二分法
这样的旋转数组有一个特性: 2部分都是递增的,那么我们可以确定的是:前半部分一定比后半部分要大,因为是非递减的
可以通过二分查找:
定义low, high,mid_location
- 当 mid_location>high的时候,我们要查找的范围在后面
- 当 mid_location<high的时候,我们要查找的范围在前面

终止条件:low<high
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
    	if(rotateArray.size()==0)
    		return 0;
    	
    	int low=0;
    	int high = rotateArray.size()-1;
        while(low<high){
        	int mid_location = (low+high)/2;
        	if(rotateArray[mid_location]>rotateArray[high])
        		low = mid_location+1;
        	else if(rotateArray[mid_location]==rotateArray[high])
        		high--;
        	else
        		high = mid_location;
        }

        return rotateArray[low];
    }
};
