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
		//统计链表中结点的个数
		while (head != nullptr)
		{
			head = head->next;
			count++;
		}
		int target = count - k; //计算倒数第k个结点的位置
		if (target < 0) //所给k值大于链表结点总数，k值不合法
			return nullptr;
		//寻找倒数第k个结点
		while (target)
		{
			pListHead = pListHead->next;
			target--;
		}
		return pListHead; //返回倒数第k个结点
	}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* front = pListHead;
		ListNode* rear = pListHead;
		//front先走k步
		while (k--)
		{
			if (front == nullptr) //所给k值大于链表结点总数，k值不合法
				return nullptr;
			front = front->next;
		}
		//front和rear一起走，直到front走到链表尾
		while (front != nullptr)
		{
			front = front->next;
			rear = rear->next;
		}
		return rear; //返回倒数第k个结点
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