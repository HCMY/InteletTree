

/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， 
{2,[3,4,2],6,2,5,1}， 
{2,3,[4,2,6],2,5,1}， 
{2,3,4,[2,6,2],5,1}， 
{2,3,4,2,[6,2,5],1}， 
{2,3,4,2,6,[2,5,1]}。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void merge(vector<int> &arr, int start, int mid, int end){
	vector<int> tmp_vec(end-start+1);
	int pre_part_idx = start;
	int second_part_idx = mid+1;
	int tmp_idx = 0;

	while(pre_part_idx<=mid && second_part_idx<=end){
		if(arr[pre_part_idx]<=arr[second_part_idx])
			tmp_vec[tmp_idx++] = arr[pre_part_idx++];
		else
			tmp_vec[tmp_idx++] = arr[second_part_idx++];
	}

	while(pre_part_idx<=mid){
		tmp_vec[tmp_idx++] = arr[pre_part_idx++];
	}
	while(second_part_idx<=end){
		tmp_vec[tmp_idx++] = arr[second_part_idx++];
	}

	for(int j=0;j<tmp_idx;j++)
		arr[start+j] = tmp_vec[j];

	tmp_vec.clear();
	//tmp_vec.swap(vector<int>(0))
}


void merge_sort(vector<int> &arr, int start, int end){
	if(start<end){
		int mid = (start+end)/2;
		merge_sort(arr,start,mid);
		merge_sort(arr,mid+1, end);
		merge(arr,start,mid,end);
	}
}




int main(int argc, char const *argv[])
{
	

	vector<int> arr = {9,8,7,6,5,4,3,2,1};
	
	merge_sort(arr,0,arr.size()-1);

	for(auto item:arr)
		cout<<item<<" ";

	return 0;
}
