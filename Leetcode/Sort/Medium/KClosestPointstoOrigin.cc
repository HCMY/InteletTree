

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;


class Solution {
public:
    static bool comp(vector<int> P1, vector<int> P2) {
        return pow(P1[0],2) + pow(P1[1],2) > pow(P2[0],2) + pow(P2[1],2);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& v, int K) {
        vector<vector<int>> ANS;
        
        make_heap(v.begin(),v.end(),comp);
        
        for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }


        while(ANS.size()!=K) {
            ANS.push_back(v.front());
            pop_heap (v.begin(),v.end(),comp); 
            v.pop_back();
        }

        return ANS;
    }
};


int main(int argc, char const *argv[])
{
    Solution solu;

    vector<vector<int>> v= {{1,3},{-2,2}};
    vector<vector<int>> ans = solu.kClosest(v,1);


    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}