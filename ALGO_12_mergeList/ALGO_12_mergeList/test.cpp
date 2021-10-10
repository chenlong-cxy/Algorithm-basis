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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		//两个链表中一个为空则返回另一个，两个都为空则返回空
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* head = nullptr; //新链表的头
		ListNode* tail = nullptr; //新链表的尾
		while (pHead1&&pHead2) //两个链表当中的结点都未取完，则循环继续
		{
			ListNode* p = pHead1->val>pHead2->val ? pHead2 : pHead1; //获取两个链表第一个结点的较小结点
			//从原链表当中删除获取到的结点
			if (p == pHead1)
				pHead1 = pHead1->next;
			else
				pHead2 = pHead2->next;
			//将获取到的结点尾插到新链表中
			if (head == nullptr){
				head = p;
				tail = p;
			}
			else{
				tail->next = p;
				tail = p;
			}
		}
		//将未取完结点的链表全部尾插到新链表后
		if (pHead1)
			tail->next = pHead1;
		else
			tail->next = pHead2;
		return head; //返回新链表
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		//两个链表中一个为空则返回另一个，两个都为空则返回空（递归的结束条件）
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* head = nullptr; //新链表的头
		//将两个链表第一个结点的较小结点尾插到新链表后
		if (pHead1->val > pHead2->val){
			head = pHead2;
			pHead2 = pHead2->next;
		}
		else{
			head = pHead1;
			pHead1 = pHead1->next;
		}
		//递归合并链表，并将合并的链表尾插到新链表后
		head->next = Merge(pHead1, pHead2);
		return head; //返回新链表
	}
};
int main()
{
	ListNode d1(1);
	ListNode d2(2);
	ListNode d3(3);
	ListNode d4(4);
	ListNode d5(5);
	ListNode d6(6);
	d1.next = &d3;
	d3.next = &d5;
	d2.next = &d4;
	d4.next = &d6;
	ListNode* p = Solution().Merge(&d1, &d2);
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}