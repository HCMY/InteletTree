
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


class Solution {
public:
	bool is_valid(int index, int start, int end){
		if(index<start || index>end)
			return false;
		return true;
	}

    bool canReach(vector<int>& arr, int start) {
 		vector<bool> visited_index(arr.size(),false);
 		queue<int> nodes_queue;
 		int end = arr.size()-1;

 		if(arr.size()==0)
 			return false;

 		nodes_queue.push(start);
 		while(!nodes_queue.empty()){
 			int tmp_index = nodes_queue.front();
 			if(arr[tmp_index]==0)
 				return true;
 			if(!visited_index[tmp_index]){
 				int add = tmp_index + arr[tmp_index];
 				int diff = tmp_index - arr[tmp_index];
 				if(is_valid(add,0,end))
 					nodes_queue.push(add);
 				if(is_valid(diff,0,end))
 					nodes_queue.push(diff);
 			}
 			visited_index[tmp_index] = true;
 			nodes_queue.pop();
 		}

 		return false;
    }
};


int main(int argc, char const *argv[])
{
	Solution solu;
	vector<int> arr1 = {4,2,3,0,3,1,2};
	vector<int> arr2 = {4,2,3,0,3,1,2};
	vector<int> arr3 = {3,0,2,1,2};

	cout<<solu.canReach(arr1,5)<<endl;
	cout<<solu.canReach(arr2,0)<<endl;
	cout<<solu.canReach(arr3,2)<<endl;

	return 0;
}