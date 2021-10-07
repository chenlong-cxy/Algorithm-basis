#include <iostream>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr) //链表为空或链表只有一个结点，无需反转
			return pHead;
		ListNode* left = pHead;
		ListNode* mid = left->next;
		ListNode* right = mid->next;
		while (right != nullptr)
		{
			//mid指向left
			mid->next = left;
			//left,mid和right统一向右移动
			left = mid;
			mid = right;
			right = right->next;
		}
		mid->next = left; //mid指向left
		pHead->next = nullptr; //第一个结点指向nullptr
		return mid; //返回新链表的表头，也就是此时的mid
	}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr) //链表为空或链表只有一个结点，无需反转
			return pHead;
		ListNode* newHead = nullptr;
		while (pHead != nullptr)
		{
			//从原链表获取第一个结点
			ListNode* p = pHead;
			pHead = pHead->next;
			//将该结点头插到新链表
			p->next = newHead;
			newHead = p;
		}
		return newHead; //返回新链表的表头
	}
};
int main()
{
	ListNode d1(1);
	ListNode d2(2);
	ListNode d3(3);
	ListNode d4(4);
	ListNode d5(5);
	d1.next = &d2;
	d2.next = &d3;
	d3.next = &d4;
	d4.next = &d5;
	ListNode* pHead = &d1;
	while (pHead)
	{
		cout << pHead->val << " ";
		pHead = pHead->next;
	}
	cout << endl;
	pHead = &d1;
	pHead = Solution().ReverseList(pHead);
	while (pHead)
	{
		cout << pHead->val << " ";
		pHead = pHead->next;
	}
	cout << endl;
	return 0;
}