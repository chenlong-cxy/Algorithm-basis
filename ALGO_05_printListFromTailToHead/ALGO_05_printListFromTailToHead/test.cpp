#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};
//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head) {
//		vector<int> v;
//		//将链表当中的数据从头到尾放到容器v当中
//		while (head != NULL)
//		{
//			v.push_back(head->val);
//			head = head->next;
//		}
//		//将容器v进行逆置
//		reverse(v.begin(), v.end());
//		return v; //返回容器v
//	}
//};

//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head) {
//		stack<int> st;
//		//依次将遍历到的结点值入栈
//		while (head != NULL)
//		{
//			st.push(head->val);
//			head = head->next;
//		}
//		vector<int> v;
//		//将栈中的数据依次出栈，存储到容器v当中
//		while (!st.empty())
//		{
//			v.push_back(st.top());
//			st.pop();
//		}
//		return v; //返回容器v
//	}
//};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		dfs(v, head); //递归进行输出
		return v;
	}
	//递归函数
	void dfs(vector<int>& v, ListNode*& pNode)
	{
		if (pNode == NULL) //传入结点地址为空，递归结束的标志
			return;
		dfs(v, pNode->next); //先递归
		v.push_back(pNode->val); //递归结束后（碰到NULL返回）再进行结点值输出
	}
};

int main()
{
	ListNode a{ 1, NULL };
	ListNode b{ 2, NULL };
	ListNode c{ 3, NULL };
	ListNode d{ 4, NULL };
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;
	vector<int> v = Solution().printListFromTailToHead(&a);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}