#include <iostream>
#include <unordered_set>
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
	ListNode* deleteDuplication(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr) //����Ϊ�ջ�ֻ��һ�����������в���
			return pHead;
		ListNode* head = new ListNode(0); //����ͷ��㣨���ڲ�����
		head->next = pHead;
		ListNode* prev = head;
		ListNode* last = prev->next;
		while (last)
		{
			while (last->next&&last->val != last->next->val)
			{
				prev = prev->next;
				last = last->next;
			}
			while (last->next&&last->val == last->next->val)
			{
				last = last->next;
			}
			//����ɾ���ģ�last->next == nullptr
			//����ɾ���ģ�last->next == nullptr
			//����ɾ���ģ�last->val != last->next->val
			if (prev->next != last)
			{
				prev->next = last->next;
			}
			last = last->next;
		}
		return head->next; //��������ͷָ��
	}
};
//class Solution {
//public:
//    ListNode* deleteDuplication(ListNode* pHead) {
//        if(pHead == nullptr||pHead->next == nullptr) //����Ϊ�ջ�ֻ��һ�����������в���
//            return pHead;
//        ListNode* cur = pHead;
//        unordered_set<int> filter;
//		//1�����������ҳ��ظ��Ľ�㣬�����ֵ����filter
//		while (cur->next)
//        {
//			if (cur->val == cur->next->val)
//				filter.insert(cur->val);
//			cur = cur->next;
//        }
//		//2�����ɾ���ظ��Ľ��
//        //��ɾ��ͷ�����ظ����
//        while(pHead&&filter.find(pHead->val) != filter.end())
//        {
//            pHead = pHead->next;
//        }
//        if(pHead == nullptr)
//            return nullptr;
//        //��ɾ��������ظ����
//        ListNode* prev = pHead;
//        ListNode* last = prev->next;
//        while(last)
//        {
//            if(filter.find(last->val) != filter.end())
//            {
//                prev->next = last->next;
//                last = last->next;
//            }
//            else
//            {
//                prev = prev->next;
//                last = last->next;
//            }
//        }
//        return pHead; //��������ͷָ��
//    }
//};
int main()
{
	ListNode d1(2);
	ListNode d2(2);
	ListNode d3(3);
	ListNode d4(3);
	ListNode d5(4);
	d1.next = &d2;
	d2.next = &d3;
	d3.next = &d4;
	d4.next = &d5;
	ListNode* p = Solution().deleteDuplication(&d1);
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}