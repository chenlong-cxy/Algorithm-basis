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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* head = pListHead;
		int count = 0;
		//ͳ�������н��ĸ���
		while (head != nullptr)
		{
			head = head->next;
			count++;
		}
		int target = count - k; //���㵹����k������λ��
		if (target < 0) //����kֵ����������������kֵ���Ϸ�
			return nullptr;
		//Ѱ�ҵ�����k�����
		while (target)
		{
			pListHead = pListHead->next;
			target--;
		}
		return pListHead; //���ص�����k�����
	}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* front = pListHead;
		ListNode* rear = pListHead;
		//front����k��
		while (k--)
		{
			if (front == nullptr) //����kֵ����������������kֵ���Ϸ�
				return nullptr;
			front = front->next;
		}
		//front��rearһ���ߣ�ֱ��front�ߵ�����β
		while (front != nullptr)
		{
			front = front->next;
			rear = rear->next;
		}
		return rear; //���ص�����k�����
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
	ListNode* ret = Solution().FindKthToTail(&d1, 1);
	cout << ret->val << endl;
	return 0;
}