#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> myMap;
		vector <int > result;
		int lenNumbers = numbers.size();
		std::map<int, int>::iterator iter;
		for (int i=0 ;i < lenNumbers; i ++) {
			int number = numbers.at(i);
			myMap[number] = i + 1;
		}
		for(int i = 0 ;i < lenNumbers; i ++) {
			int number = numbers.at(i);
			int needFindNumber = target -number;
			iter = myMap.find(needFindNumber);
			if(iter != myMap.end()) {
				int findNumberIndex = iter ->second;
				if(i + 1 < findNumberIndex) {
					result.push_back(i +1);
					result.push_back(findNumberIndex);
				} else if(i + 1 > findNumberIndex) {
					result.push_back(findNumberIndex);
					result.push_back(i + 1);
				}
			} 
			continue;
		}
		return result;
    }
};

int main() {
	int myarray[5] = {2,1,4,0,5};  
	vector <int> myvector(myarray , myarray+5); 
	vector <int> result;
	Solution *solution = new Solution();
	result = solution -> twoSum(myvector ,3);
	printf("index == %d %d\n", result.at(0), result.at(1));
	return 0;
}
