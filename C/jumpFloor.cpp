#include"stdafx.h"
int jumpFloor(int number) {
	int number1 = 1;
	int number2 = 2;
	if(number == number1) return number1;
	if(number == number2) return number2;

	int result=0;
	for(int i = 3; i<=number; i++) {
		result = number1 + number2;
		number1 = number2;
		number2 = result;
	}
	return result;
}