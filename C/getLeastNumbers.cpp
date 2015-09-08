#include"stdafx.h"
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
using namespace std;
//获得最小的k个数
//2种思路
//思路1：利用快排的思想，找到下标为k的基数，这样k之前的数为最小的k个数。O(n)
//思路2：使用一个容器记录最小的k个数，每次读入一个数，和容器里的最大数对比；
//如果小于最大数,删除最大数，并插入这个数。可以采用最大堆，但是最大堆写起来需要一定的时间，这里使用multiset(STL中基于红黑树实现)
int partition(vector<int> &numbers, int start ,int end);

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {   
	int length = input.size();
	vector<int> result;
	if(length == 0 || k<=0 || k > length)  return result;
	int start = 0;
	int end = length-1;
	int index = partition(input,start, end);
	while(index != (k-1)) {
		if(index < (k-1)) {
			start = index+1;
			index = partition(input, start, end);
		} else  {
			end = index -1;
			index = partition(input, start ,end);
		}
	}

	//找到位置在k的基数，遍历前k个数
	for(int i =0 ; i < k; i++) {
		result.push_back(input[i]);
	}
	return result;
}


//分区，partition
//int partition(vector<int> &numbers, int start ,int end)
//{
//
//	int key = numbers.at(start);
//	int i = start;
//	int j = end;
//	while(i < j) {
//		//从右向左扫描
//		while( i<j && key < numbers.at(j) )
//			j--;
//		//交换元素
//		if(i < j) {
//			int temp = key;
//			numbers[i] = numbers[j];
//			numbers[j] = temp;
//			i++;
//		}
//		//从左向右扫描
//		while(i < j && key >= numbers.at(i) ) 
//			i++;
//		if(i < j) {
//			int temp = numbers.at(i);
//			numbers[i]  = numbers[j];
//			numbers[j] = temp;
//		}
//	}
//	numbers[i] = key;
//	return i;
//}


//方法2，使用红黑树来保存k个小数，并更新这个容器
vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
	int length = input.size();
	vector<int> result;
	if(length ==0 || k < 0 || k > length) return result;

	multiset<int,less<int>> leastNumbers;
	leastNumbers.clear();

	vector<int>::const_iterator iter = input.begin();
	for(; iter!= input.end(); iter++) {
		if(leastNumbers.size()  < k) {
			leastNumbers.insert(*iter);
		} else {
			multiset<int, less<int>>::iterator iterGreatest = leastNumbers.end();
			iterGreatest--;
			if(*iter < *iterGreatest) {
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}

	for(multiset<int, greater<int>>::iterator iter = leastNumbers.begin(); iter!=leastNumbers.end(); iter++) {
		result.push_back(*iter);
	}
	return result;
}

int main()
{
	int input[] = {4,5,1,6,2,7,3,8};
	vector<int> inputVector(input, input+sizeof(input)/sizeof(int));
	vector<int> result = getLeastNumbers_Solution(inputVector,4);
	for(int i = 0; i<result.size(); i++) {
		printf("%d ", result[i]);
	}
	return 0;
}
