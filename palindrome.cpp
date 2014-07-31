#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
	int min(int a,int b) {
		return a<b?a:b;
	}
    int minCut(string s) {
		int lenString = s.size();
		int dp[lenString + 1];
		bool dmap[lenString+1][lenString+1];
		for(int i=0;i<=lenString;i++) {
			for(int j=0;j<=lenString;j++) {
				dmap[i][j] = false;
			}
			dmap[i][i] = true;
		}
		for(int i=lenString;i>=0;i--) {
			dp[i] = lenString - i;
		}
		dp[lenString] = 0; 
		for(int i= lenString-1;i >= 0;i--) {
			for(int j= i+1;j < lenString;j++) {
				if(s.at(i) == s.at(j)&& (j-i<2 || dmap[i+1][j-1])) {
					dmap[i][j] = true;
					dp[i] = min(dp[i],dp[j+1]+1);
				}
			}
			dp[i] = min(dp[i],dp[i+1] + 1);
		}
		return dp[0]-1;
    }
};

int main()
{
	string inputString = "cdd";
	printf("%lu\n",inputString.size());
	Solution *test = new Solution();
	printf("%d\n",test->minCut(inputString));
	return 0;
}