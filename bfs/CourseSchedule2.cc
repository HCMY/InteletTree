


#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    	
        vector<int> in_degree(numCourses,0);
        map<int, vector<int>> table;
        queue<int> my_queue;
        vector<int> res;

        if(numCourses<0)
            return res;
        if(prerequisites.size()==0){
            for(int i=0;i<numCourses;i++)
                res.push_back(i);

            return res;
        }


        // generate indegree and linked table
        int rows = prerequisites.size();
        int cols = prerequisites[0].size();
        for(int i=0;i<rows;i++){
        	in_degree[prerequisites[i][0]]++;
        	int key = prerequisites[i][1];
        	int value = prerequisites[i][0];
        	if(table.count(key))
        		table[key].push_back(value);
        	else
        		table[key] = {value};
        }
        
        for(int i=0;i<numCourses;i++){
        	if(in_degree[i]==0)
        		my_queue.push(i);
        }

        while(!my_queue.empty()){
        	int tmp_key = my_queue.front();
        	for(auto key:table[tmp_key]){
        		in_degree[key]--;
        		if(in_degree[key]==0)
        			my_queue.push(key);
        	}
        	res.push_back(my_queue.front());
        	my_queue.pop();

        }

        for(auto key:in_degree){
        	if(in_degree[key]!=0){
                vector<int> empty_vec;
        		return empty_vec;
            }
        }

        return res;
    }
};


int main(int argc, char const *argv[])
{
	Solution solu;

	vector<vector<int>> arr1 = {{1,0}};
	vector<vector<int>> arr2 = {{1,0},{2,0},{3,1},{3,2}};

    vector<int> ans;
    ans = solu.findOrder(2,arr1);
	for(auto item:ans)
        cout<<item<<" ";
    cout<<endl;

    ans.clear();
    ans = solu.findOrder(4,arr2);
    for(auto item:ans)
        cout<<item<<" ";
    cout<<endl;

	return 0;
}