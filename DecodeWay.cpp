#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int lenS = s.size();
        if(lenS == 0) return 0;
		if(lenS == 1 && s.at(0)=='0') return 0;
		else if(lenS == 1 && s.at(0)!='0') return 1;
		int dp[lenS];
		int firstNum = s.at(0) - '0';
		int scondNum = s.at(1) - '0';
		for(int i=0;i<lenS;i++) dp[i] = 0;
		if(firstNum == 0) return 0;
		dp[0] = 1;
		if(scondNum != 0) dp[1] =dp[0];
		if(scondNum+firstNum*10 >=10 &&scondNum + firstNum*10 <=26) dp[1] +=1;
		if(dp[1]==0) return 0;
		for(int i=2;i<lenS;i++) {
			firstNum = scondNum;
			scondNum = s.at(i)-'0';
			if(scondNum!=0) dp[i] = dp[i-1];
			if(scondNum+firstNum*10 >=10 &&scondNum + firstNum*10 <=26) {
				dp[i]+=dp[i-2];
			}
			if(dp[i]==0) return 0;
		}
		return dp[lenS-1];
    }
};

int main() {
	Solution *test = new Solution();
	printf("%d\n",test->numDecodings("11"));
	return 0;
}