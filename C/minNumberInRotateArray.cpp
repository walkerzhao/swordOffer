//旋转数组中找最小值
#include"stdafx.h"
#include<vector>
using namespace std;
int minNumberInRotateArray(vector<int> rotateArray) {
	int length = rotateArray.size();
	if(length == 0) return 0;
	int start = 0;
	int end = length-1;
	int middle = (start+end)/2;

	if(rotateArray[start] < rotateArray[end])
		return rotateArray[start];
	
	while(1) {
		if((end-start) == 1) return rotateArray[end];
		if(rotateArray[middle] > rotateArray[start]) {
			start = middle;
		} else if(rotateArray[middle] < rotateArray[end]) {
			end  = middle;
		} else {
			return minInorder(rotateArray); 
		}
			
		middle = (start+end)/2;
	}
}

int minInorder(vector<int> rotateArray) {
	int length = rotateArray.size();
	int min = rotateArray[0];
	for(int i= 1; i<length; i++) {
		if(rotateArray[i] < min)
			min = rotateArray[i];
	}
	return min;
}

int main()
{
	int a[] = {3,4,5,1,2};
	vector<int> input(a,a+5);
	int result = minNumberInRotateArray(input);
	printf("%d\n",result);
	return 0;
}
