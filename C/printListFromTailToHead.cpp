//从尾到头打印单链表
//能不能改变单链表的话，如果可以反转单链表
//不能改变的话，遍历单链表，将value入栈，遍历结束的时候，将栈中元素出栈即可。
//通过循环和栈的实现，一般都可以转换成递归来实现

#include "stdafx.h"
#include<vector>
#include<stack>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


vector<int> printListFromTailToHead(struct ListNode* head) {
	vector<int> result;
	if(head == NULL) return result;

	stack<int> nodes;

	ListNode * pNode = head;
	while(pNode != NULL) {
		nodes.push(pNode->val);
		pNode = pNode->next;
	}

	while(!nodes.empty()) {
		result.push_back(nodes.top());
		nodes.pop();
	}

	return result;
}