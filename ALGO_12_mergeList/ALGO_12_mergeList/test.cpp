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
		//����������һ��Ϊ���򷵻���һ����������Ϊ���򷵻ؿ�
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* head = nullptr; //�������ͷ
		ListNode* tail = nullptr; //�������β
		while (pHead1&&pHead2) //���������еĽ�㶼δȡ�꣬��ѭ������
		{
			ListNode* p = pHead1->val>pHead2->val ? pHead2 : pHead1; //��ȡ���������һ�����Ľ�С���
			//��ԭ������ɾ����ȡ���Ľ��
			if (p == pHead1)
				pHead1 = pHead1->next;
			else
				pHead2 = pHead2->next;
			//����ȡ���Ľ��β�嵽��������
			if (head == nullptr){
				head = p;
				tail = p;
			}
			else{
				tail->next = p;
				tail = p;
			}
		}
		//��δȡ���������ȫ��β�嵽�������
		if (pHead1)
			tail->next = pHead1;
		else
			tail->next = pHead2;
		return head; //����������
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		//����������һ��Ϊ���򷵻���һ����������Ϊ���򷵻ؿգ��ݹ�Ľ���������
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* head = nullptr; //�������ͷ
		//�����������һ�����Ľ�С���β�嵽�������
		if (pHead1->val > pHead2->val){
			head = pHead2;
			pHead2 = pHead2->next;
		}
		else{
			head = pHead1;
			pHead1 = pHead1->next;
		}
		//�ݹ�ϲ����������ϲ�������β�嵽�������
		head->next = Merge(pHead1, pHead2);
		return head; //����������
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