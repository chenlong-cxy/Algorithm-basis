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
		if (beginSub == nullptr) //beginSub为nullptr，说明已经比较完了
			return true;
		if (begin == nullptr) //beginSub未比较完，但begin已经比较完了
			return false;
		if (begin->val != beginSub->val) //结点值不相同，返回false
			return false;
		//结点值相同，且左子树和右子树相同则为相同的树
		return IsSame(begin->left, beginSub->left) && IsSame(begin->right, beginSub->right);
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot1 == nullptr || pRoot2 == nullptr) //pRoot1已经遍历完毕或pRoot2为空，则返回false
			return false;
		bool result = false;
		//找到起始位置
		if (pRoot1->val == pRoot2->val)
		{
			//从起始位置开始，判断两棵树是否相同
			result = IsSame(pRoot1, pRoot2);
		}
		//从左子树寻找匹配的起始位置
		if (result != true)
		{
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		//从右子树寻找匹配的起始位置
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
//	//以下为排序操作
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
//	//输出
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