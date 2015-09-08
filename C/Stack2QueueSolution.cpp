//使用两个栈实现一个队列
#include"stdafx.h"
#include<stack>
using namespace std;

class Solution
{
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
		if(stack2.empty()) {
			if(stack1.empty()) return 0;
			while(!stack1.empty()) {
				int node = stack1.top();
				stack2.push(node);
				stack1.pop();
			}
		}
		int value = stack2.top();
		stack2.pop();  
		return value;
    }


};