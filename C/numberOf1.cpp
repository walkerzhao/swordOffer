#include "stdafx.h"
//题目：给一个整数，输出该数二进制表示中1的个数


//对于负数，可能会造成死循环
//int numberOf1(int n)
//{
//	int count = 0;
//	while(n) {
//		int result = n&1;
//		if(result == 1) count++;
//		n = n>>1;
//	}
//	return count;
//}
//可以解决负数陷入死循环的问题，但是需要循环32次，效率不高。
//int numberOf1(int n)
//{
//	int count = 0;
//	unsigned int flag = 1;
//	while(flag) {
//		if(n & flag)
//			count++;
//		flag = flag << 1;
//	}
//	return count;
//}

//使用n&(n-1)将最右边一个1变为0
int numberOf1(int n)
{
	int count = 0;
	while(n) {
		count++;
		n = n&(n-1);
	}
	return count;
}

int main()
{
	int result = numberOf1(9999);
	printf("%d\n",result);

	return 0;
}

//test
//0x80000000
//9999