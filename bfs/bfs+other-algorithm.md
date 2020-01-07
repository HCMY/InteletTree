# BFS+Other Algorithm

### Network Delay Time

There are `N` network nodes, labelled `1` to `N`. Given `times`, a list of travel times as **directed** edges `times[i] = (u, v, w)`, where `u` is the source node, `v` is the target node, and `w` is the time it takes for a signal to travel from source to target. Now, we send a signal from a certain node `K`. How long will it take for all nodes to receive the signal? If it is impossible, return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png)

```text
Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
```

这道题，因为边带有权重，且题目给定了起始点，所以本质上是求单源最短路径的问题，可以通过Dijkstra算法求得图中每个点到初始点的最短距离，然后返回这些距离里面最长的一个就可以了。

#### Dijkstra算法

Dijkstra算法，和贪心有些类似:每次遍历都只寻找初始点A距离最近的点。比如下图：A到E的最短路径就是A-&gt;D-&gt;C-&gt;E。那么这个步骤是如下的：

Dijkstra需要几个辅助信息：  
1. 一个记录各点与A最近距离的数组: dist  
2. 一个纪录下已获得最近距离的点的数组 visited  
3. 按情况而异，这里我们使用连接矩阵表示各个点之间的连接情况，如果点点之间有连接，那么矩阵对应位置的值就是权重，否则设置为一个较大的数字，cost矩阵  


1. 初始化dist数组，dist\[i\] 的值为A到i的距离，若A-i相连，值为权重，否则为无穷大 先从A出发，找遍所有结点，找到和A最近的点，注意：如果节点之间不相连，则权重为无穷大，这也是为什么cost矩阵含有无穷大的原因。我们找到了与A直接相连的最近的是D，下一个开始的点是D。
2. 从离A最近的点D开始，我们发现D的加入，导致了A到B点的最短距离为 A-D-B，所以此处，我们相应的需要更新 A-B的距离
3. 重复上面的步骤寻找，直到遍历完所有的点，每次遍历，只更新一个点。



![Graph](../.gitbook/assets/image%20%283%29.png)

```cpp
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

```

