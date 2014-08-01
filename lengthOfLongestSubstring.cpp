#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int vist[1000] = { 0 };
		int lenString = s.size();
		if(lenString == 0) return 0;
		int fr = 0 ,result = 1;
		for(int i = 0 ;i < lenString ;i ++) {
			int id = s.at(i) - 0;
			while(vist[id] && fr < i) {
				int frontID = s.at(fr) - 0;
				vist[frontID] = 0;
				fr ++;
			}
			vist[id] = 1;
			result = result > (i - fr + 1) ? result : (i - fr + 1);
		}
		return result;
    }
};

int main() {
	string testString = "sbdesertyuio";
	Solution *solution = new Solution();
	int result = solution -> lengthOfLongestSubstring(testString);
	printf("result == %d\n", result);
	return 0;
}