#include "stdafx.h"

int Fibonacci(int n) {
	long long fibNMinusOne = 0;
	long long fibNMinusTwo = 1;
	if(n == 0)
		return fibNMinusOne;
	if(n == 1)
		return fibNMinusTwo;

	long long fibN = 0;
	for(int i=2; i<=n; i++) {
		fibN = fibNMinusOne+fibNMinusTwo;
		fibNMinusOne = fibNMinusTwo;
		fibNMinusTwo = fibN;
	}
	return fibN;
}

int main()
{
	int result = Fibonacci(20);
	printf("%ld\n",result);
	return 0;
}