
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    static bool comp(vector<int> P1, vector<int> P2) {
        return pow(P1[0],2) + pow(P1[1],2) < pow(P2[0],2) + pow(P2[1],2);
    }



    void adjust(vector<vector<int>>& v, int node, int size){
        int left = 2*node+1;
        int right = 2*node+2;
        int small = node;
        if(left<size && comp(v[left],v[node]))
            small = left;
        if(right<size && comp(v[right],v[node]))
            small = right;
        if(small!=node){
            swap(v[small],v[node]);
            adjust(v,node,size);
        }
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& v, int K) {
        vector<vector<int>> ANS;

        for(int i=v.size()/2-1; i>=0;i--)
            adjust(v,i,v.size());

        
        int size = v.size()-1;
        while(ANS.size()!=K){
            ANS.push_back(v[0]);
            swap(v[0],v[size]);
            size--;
            adjust(v,0,size+1);
        }

        for(auto item:ANS)
            cout<<item[0]<<" "<<item[1]<<endl;

        return ANS;
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    vector<vector<int>> v1={{3,3},{5,-1},{-2,4}};
    vector<vector<int>> v2={{1,3},{-2,2},{2,-2}};
    solu.kClosest(v1,2);
    solu.kClosest(v2,2);
    return 0;
}
