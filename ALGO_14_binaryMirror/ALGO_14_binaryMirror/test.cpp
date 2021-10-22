#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* Mirror(TreeNode* pRoot) {
		if (pRoot == nullptr) //�������辵��
			return nullptr;
		TreeNode* left = Mirror(pRoot->left); //���ý�������������
		TreeNode* right = Mirror(pRoot->right); //���ý��Ľ�����������
		//�����ý�����������
		pRoot->left = right;
		pRoot->right = left;
		return pRoot; //���ظý��
	}
};
class Solution {
public:
	TreeNode* Mirror(TreeNode* pRoot) {
		if (pRoot == nullptr) //�������辵��
			return nullptr;
		queue<TreeNode*> q;
		q.push(pRoot); //�Ƚ�����������
		while (!q.empty())
		{
			//ȡ��ͷ���
			TreeNode* pNode = q.front();
			q.pop();
			//�����ý�����������
			TreeNode* temp = pNode->left;
			pNode->left = pNode->right;
			pNode->right = temp;
			//���ý������㲻Ϊ�գ��������������
			if (pNode->left)
				q.push(pNode->left);
			//���ý����ҽ�㲻Ϊ�գ������ҽ�������
			if (pNode->right)
				q.push(pNode->right);
		}
		return pRoot; //���ظ����
	}
};
class Solution {
public:
	TreeNode* Mirror(TreeNode* pRoot) {
		if (pRoot == nullptr) //�������辵��
			return nullptr;
		stack<TreeNode*> st;
		st.push(pRoot); //�Ƚ��������ջ
		while (!st.empty())
		{
			//ȡջ�����
			TreeNode* pNode = st.top();
			st.pop();
			//�����ý�����������
			TreeNode* temp = pNode->left;
			pNode->left = pNode->right;
			pNode->right = temp;
			//���ý������㲻Ϊ�գ�����������ջ
			if (pNode->left)
				st.push(pNode->left);
			//���ý����ҽ�㲻Ϊ�գ������ҽ����ջ
			if (pNode->right)
				st.push(pNode->right);
		}
		return pRoot; //���ظ����
	}
};
void Print(TreeNode* p)
{
	queue<TreeNode*> q;
	q.push(p);
	while (!q.empty())
	{
		TreeNode* tmp = q.front();
		q.pop();
		cout << tmp->val << " ";
		if (tmp->left)
		{
			q.push(tmp->left);
		}
		if (tmp->right)
		{
			q.push(tmp->right);
		}
	}
}
int main()
{
	TreeNode d8(8);
	TreeNode d6(6);
	TreeNode d10(10);
	TreeNode d5(5);
	TreeNode d7(7);
	TreeNode d9(9);
	TreeNode d11(11);
	d8.left = &d6;
	d8.right = &d10;
	d6.left = &d5;
	d6.right = &d7;
	d10.left = &d9;
	d10.right = &d11;
	TreeNode* p = Solution().Mirror(&d8);
	Print(p);
	return 0;
}