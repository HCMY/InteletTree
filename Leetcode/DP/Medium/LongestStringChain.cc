#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isPre(string & a,string & b){
        if (a.size() >= b.size())
        	return false;
        for (int i = 0; i < b.size(); i++) {
            if (a[i] != b[i]) return a.substr(i) == b.substr(i + 1);
        }
        return true;
    }

class Solution {
public:

    int longestStrChain(vector<string>& words) {
  		int len = words.size();
  		vector<int> dp(len,1);

  		auto cmp = [](string & a, string& b) {
            return a.size() < b.size();
        };
  		sort(words.begin(), words.end(), cmp);

  		int pre_max = 0;
  		for(int i=1;i<len;i++){
  			for(int j=0;j<i;j++){
  				if (isPre(words[j],words[i])){
  					dp[i] = max(dp[i],dp[j]+1);
  				}
  			pre_max = max(pre_max,dp[i]);
  			}
  		}

  		return pre_max;
    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	vector<string> words1 = {"a","b","ba","bca","bda","bdca"};
	vector<string> words2 = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj",
		"ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
	
	cout<<solu.longestStrChain(words1)<<endl;
	cout<<solu.longestStrChain(words2)<<endl;
	return 0;
}