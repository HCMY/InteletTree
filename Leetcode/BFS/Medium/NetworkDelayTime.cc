

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INFINITY 9999

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> distance(N+1,INFINITY);
        vector<vector<int>> cost(N+1,vector<int>(N+1,INFINITY));
        vector<bool> visited(N+1,false);
        int tmp_min;
        int nextnode;

        

        for(auto item:times)
        	cost[item[0]][item[1]] = item[2];
        for(int i=1;i<=N;i++)
        	distance[i] = cost[K][i];
       
        distance[K] = 0;
        visited[K] = true;
        int count = 1;
        while(count<N-1){
        	tmp_min = INFINITY;
        	for(int i=1;i<=N;i++){
        		if(distance[i]<tmp_min && !visited[i]){
        			tmp_min = distance[i];
        			nextnode = i;
        		}
        	}
        	visited[nextnode] = true;
        	for(int i=1;i<=N;i++){
        		if((tmp_min+cost[nextnode][i])<distance[i] && !visited[i]){
        			distance[i] = tmp_min+cost[nextnode][i];
        			}
        		}

        	count++;
        	}

        int max_time = *max_element(distance.begin()+1,distance.end());

        return max_time==INFINITY?-1:max_time;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;

	vector<vector<int>> mat = {{1,2,1}};//{{2,1,1},{2,3,1},{3,4,1}};
	cout<<solu.networkDelayTime(mat,2,1)<<endl;

	return 0;
}