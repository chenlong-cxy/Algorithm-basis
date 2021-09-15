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
//		//�������е����ݴ�ͷ��β�ŵ�����v����
//		while (head != NULL)
//		{
//			v.push_back(head->val);
//			head = head->next;
//		}
//		//������v��������
//		reverse(v.begin(), v.end());
//		return v; //��������v
//	}
//};

//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head) {
//		stack<int> st;
//		//���ν��������Ľ��ֵ��ջ
//		while (head != NULL)
//		{
//			st.push(head->val);
//			head = head->next;
//		}
//		vector<int> v;
//		//��ջ�е��������γ�ջ���洢������v����
//		while (!st.empty())
//		{
//			v.push_back(st.top());
//			st.pop();
//		}
//		return v; //��������v
//	}
//};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		dfs(v, head); //�ݹ�������
		return v;
	}
	//�ݹ麯��
	void dfs(vector<int>& v, ListNode*& pNode)
	{
		if (pNode == NULL) //�������ַΪ�գ��ݹ�����ı�־
			return;
		dfs(v, pNode->next); //�ȵݹ�
		v.push_back(pNode->val); //�ݹ����������NULL���أ��ٽ��н��ֵ���
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