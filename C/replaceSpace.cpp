//替换字符串中的空格为%20
//弄清楚能否允许开辟新的空间去存储，这里不新开辟存储空间
//思路：先统计空格的个数，计算出转换后的空间，然后从后面向前面替换空格
#include "stdafx.h"
#include<string.h>

void replaceSpace(char *str,int length) {
	if(str == nullptr) return;
	int spaceCount = 0;
	for(int i=0;i < length; i++) {
		if(str[i] == ' ') spaceCount++;
	}
	int afterLength = length + spaceCount*2;

	int indexOfOriginal = length-1;
	int indexOfNew = afterLength-1;
	while(indexOfOriginal >=0 && indexOfNew > indexOfOriginal) {
		if(str[indexOfOriginal] == ' ') {
			str[indexOfNew --] = '0';
			str[indexOfNew --] = '2';
			str[indexOfNew --] = '%';
			indexOfOriginal--;
		} else {
			str[indexOfNew --] = str[indexOfOriginal--];
		}
	}
}

int main()
{
	char input[20] = "hello world";
	replaceSpace(input,strlen(input)+1);
	printf("%s\n",input);
	return 0;
}
