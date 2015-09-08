//获取字符串中第一个只出现一次的字符
//思路：遍历字符串，和后面的每一个字符比较，如果没有重复就返回,O(n^2)
//换种思路：和次数相关，那我们统计次数。遍历字符串，统计每个字符出现的次数(哈希表存储）；第二次遍历，从哈希表中取数据，如果次数为1就返回
#include "stdafx.h"
#include<string>
using namespace std;
int firstNotRepeatingChar(string str) {
	int length = str.length();
	if(length == 0) return -1;

	//遍历，计数
	int hashTable[256]={0};
	for(int i=0; i< length; i++) {
		hashTable[str.at(i)]++;
	}
	//遍历，查找计数
	int i=0;
	for(i=0; i< length; i++) {
		if(hashTable[str.at(i)] == 1)
			return i;
	}
	if(i == length)
		return -1;
}


int main()
{
	string input = "hehllo,world";
	int index = firstNotRepeatingChar(input);
	printf("%d\n",index);
	return 0;
}

