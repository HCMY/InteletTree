/**
Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int partition(vector<int> &nums, int low, int high){
    	int pivot = nums[low];
    	while(low<high){
    		while(low<high && nums[high]<=pivot)
    			high--;
    		nums[low] = nums[high];
    		while(low<high && nums[low]>=pivot)
    			low++;
    		nums[high] = nums[low];
    	}
    	nums[low] = pivot;
    	return low;
    }

    void qsort(vector<int> &nums, int low, int high, int k){
    	if(low<high){
    		int pos = partition(nums,low,high);
    		if(pos+1==k)
    			return;
    		else if(pos+1>k)
    			qsort(nums,low,pos-1,k);
    		else
    			qsort(nums,pos+1,high,k);
    	}
    }

    int findKthLargest(vector<int>& nums, int k) {
    	qsort(nums,0,nums.size()-1,k);
    	return nums[k-1];
    }
};



int main(int argc, char const *argv[])
{
	vector<int> nums={3,2,1,5,6,4};
	Solution solu;
	cout<<solu.findKthLargest(nums,2)<<endl;
	return 0;
}