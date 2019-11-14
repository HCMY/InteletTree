/**

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
    	if(N<2) return false;

  		vector<bool> dp(N);
  		dp[1] = false;

  		for(int i=2; i<=N;i++){
  			for(int j=1;j<i;j++){
  				if(i%j==0 && !dp[i-j]){
  					dp[i] = true;
  					break;
  				}
  			}
  		}

  		return dp[N];

    }
};

int main(int argc, char const *argv[])
{
	Solution solu;
	cout<<solu.divisorGame(4)<<endl;
	cout<<solu.divisorGame(5)<<endl;
	cout<<solu.divisorGame(6)<<endl;
	cout<<solu.divisorGame(7)<<endl;
	


	return 0;
}