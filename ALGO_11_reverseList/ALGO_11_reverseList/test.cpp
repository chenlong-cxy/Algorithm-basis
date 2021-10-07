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
		if (pHead == nullptr || pHead->next == nullptr) //����Ϊ�ջ�����ֻ��һ����㣬���跴ת
			return pHead;
		ListNode* left = pHead;
		ListNode* mid = left->next;
		ListNode* right = mid->next;
		while (right != nullptr)
		{
			//midָ��left
			mid->next = left;
			//left,mid��rightͳһ�����ƶ�
			left = mid;
			mid = right;
			right = right->next;
		}
		mid->next = left; //midָ��left
		pHead->next = nullptr; //��һ�����ָ��nullptr
		return mid; //����������ı�ͷ��Ҳ���Ǵ�ʱ��mid
	}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr) //����Ϊ�ջ�����ֻ��һ����㣬���跴ת
			return pHead;
		ListNode* newHead = nullptr;
		while (pHead != nullptr)
		{
			//��ԭ�����ȡ��һ�����
			ListNode* p = pHead;
			pHead = pHead->next;
			//���ý��ͷ�嵽������
			p->next = newHead;
			newHead = p;
		}
		return newHead; //����������ı�ͷ
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