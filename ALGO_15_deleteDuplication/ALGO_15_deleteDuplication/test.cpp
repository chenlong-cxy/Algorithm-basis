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
		if (pHead == nullptr || pHead->next == nullptr) //链表为空或只有一个结点无需进行操作
			return pHead;
		ListNode* head = new ListNode(0); //创建头结点（便于操作）
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
			//无需删除的，last->next == nullptr
			//有需删除的，last->next == nullptr
			//有需删除的，last->val != last->next->val
			if (prev->next != last)
			{
				prev->next = last->next;
			}
			last = last->next;
		}
		return head->next; //返回链表头指针
	}
};
//class Solution {
//public:
//    ListNode* deleteDuplication(ListNode* pHead) {
//        if(pHead == nullptr||pHead->next == nullptr) //链表为空或只有一个结点无需进行操作
//            return pHead;
//        ListNode* cur = pHead;
//        unordered_set<int> filter;
//		//1、遍历链表找出重复的结点，将结点值存入filter
//		while (cur->next)
//        {
//			if (cur->val == cur->next->val)
//				filter.insert(cur->val);
//			cur = cur->next;
//        }
//		//2、逐个删除重复的结点
//        //先删除头部的重复结点
//        while(pHead&&filter.find(pHead->val) != filter.end())
//        {
//            pHead = pHead->next;
//        }
//        if(pHead == nullptr)
//            return nullptr;
//        //再删除其余的重复结点
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
//        return pHead; //返回链表头指针
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