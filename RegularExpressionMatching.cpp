#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define N 1009
using namespace std;

int matchMap[N][N];

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		if(*p == '\0') return *s == '\0';
		if(*(p+1) != '*') {
			if(*s != '\0' && (*p == '.' || *p == *s)) return isMatch(s+1,p+1);
			else return false;
		} else {
			while(*s != '\0' && (*s == *p || *p == '.')) {
				if(isMatch(s,p+2)) return true;
				s ++;
			}
			return isMatch(s, p+2);
		}
	}
};

int main() {
	char s[] = "aaa";
	char p[] = "aa";
	Solution *test = new Solution();
	bool flag = test->isMatch(s,p);
	if(flag) {
		printf("test true\n");
	} else {
		printf("test false\n");
	} 
	return 0;
}