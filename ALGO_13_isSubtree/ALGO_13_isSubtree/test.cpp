#include <iostream>
using namespace std;
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	bool IsSame(TreeNode* begin, TreeNode* beginSub)
	{
		if (beginSub == nullptr) //beginSubΪnullptr��˵���Ѿ��Ƚ�����
			return true;
		if (begin == nullptr) //beginSubδ�Ƚ��꣬��begin�Ѿ��Ƚ�����
			return false;
		if (begin->val != beginSub->val) //���ֵ����ͬ������false
			return false;
		//���ֵ��ͬ��������������������ͬ��Ϊ��ͬ����
		return IsSame(begin->left, beginSub->left) && IsSame(begin->right, beginSub->right);
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot1 == nullptr || pRoot2 == nullptr) //pRoot1�Ѿ�������ϻ�pRoot2Ϊ�գ��򷵻�false
			return false;
		bool result = false;
		//�ҵ���ʼλ��
		if (pRoot1->val == pRoot2->val)
		{
			//����ʼλ�ÿ�ʼ���ж��������Ƿ���ͬ
			result = IsSame(pRoot1, pRoot2);
		}
		//��������Ѱ��ƥ�����ʼλ��
		if (result != true)
		{
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		//��������Ѱ��ƥ�����ʼλ��
		if (result != true)
		{
			result = HasSubtree(pRoot1->right, pRoot2);
		}
		return result;
	}
};
int main()
{
	TreeNode dA(1);
	TreeNode dB(2);
	TreeNode dC(3);
	TreeNode dD(4);
	TreeNode dE(1);
	TreeNode dF(2);
	TreeNode dG(3);
	dA.left = &dB;
	dA.right = &dC;
	dB.left = &dD;
	dE.left = &dF;
	dE.right = &dG;
	cout << Solution().HasSubtree(&dA, &dE) << endl;
	return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//#include<malloc.h>
//typedef struct Lnode
//{
//	int data;
//	struct Lnode *next;
//}LinkNode;
//void Creat(LinkNode *&L, int n)
//{
//	L = (LinkNode *)malloc(sizeof(LinkNode));
//	L->next = NULL;
//	int i;
//	LinkNode *p, *r;
//	r = L;
//	for (i = 0; i<n; i++)
//	{
//		p = (LinkNode *)malloc(sizeof(LinkNode));
//		scanf("%d", &p->data);
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//}
//void Print(LinkNode *head1, LinkNode *head2)
//{
//	LinkNode *head, *r;
//	head = head1;
//	while (head->next != NULL)
//	{
//		head = head->next;
//	}
//	head->next = head2->next;
//	head = head1;
//
//	//����Ϊ�������
//	LinkNode *p, *min;
//	int t;
//	r = head->next;
//	while (r != NULL)
//	{
//		min = r;
//		p = r;
//		while (p != NULL)
//		{
//			if (min->data < p->data)
//			{
//				min = p;
//			}
//			p = p->next;
//		}
//
//		t = r->data;
//		r->data = min->data;
//		min->data = t;
//
//		r = r->next;
//	}
//	head = head->next;
//	//���
//	while (head != NULL)
//	{
//		printf("%d ", head->data);
//		head = head->next;
//	}
//	printf("\n");
//}
//int main()
//{
//	int n, m;
//	LinkNode *head1, *head2;
//	scanf("%d", &n);
//	Creat(head1, n);
//	scanf("%d", &m);
//	Creat(head2, m);
//	Print(head1, head2);
//	return 0;
//}