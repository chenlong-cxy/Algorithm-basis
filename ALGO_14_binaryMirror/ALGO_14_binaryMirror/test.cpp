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
		if (pRoot == nullptr) //空树无需镜像
			return nullptr;
		TreeNode* left = Mirror(pRoot->left); //将该结点的左子树镜像
		TreeNode* right = Mirror(pRoot->right); //将该结点的将右子树镜像
		//交换该结点的左右子树
		pRoot->left = right;
		pRoot->right = left;
		return pRoot; //返回该结点
	}
};
class Solution {
public:
	TreeNode* Mirror(TreeNode* pRoot) {
		if (pRoot == nullptr) //空树无需镜像
			return nullptr;
		queue<TreeNode*> q;
		q.push(pRoot); //先将根结点入队列
		while (!q.empty())
		{
			//取队头结点
			TreeNode* pNode = q.front();
			q.pop();
			//交换该结点的左右子树
			TreeNode* temp = pNode->left;
			pNode->left = pNode->right;
			pNode->right = temp;
			//若该结点的左结点不为空，则将其左结点入队列
			if (pNode->left)
				q.push(pNode->left);
			//若该结点的右结点不为空，则将其右结点入队列
			if (pNode->right)
				q.push(pNode->right);
		}
		return pRoot; //返回根结点
	}
};
class Solution {
public:
	TreeNode* Mirror(TreeNode* pRoot) {
		if (pRoot == nullptr) //空树无需镜像
			return nullptr;
		stack<TreeNode*> st;
		st.push(pRoot); //先将根结点入栈
		while (!st.empty())
		{
			//取栈顶结点
			TreeNode* pNode = st.top();
			st.pop();
			//交换该结点的左右子树
			TreeNode* temp = pNode->left;
			pNode->left = pNode->right;
			pNode->right = temp;
			//若该结点的左结点不为空，则将其左结点入栈
			if (pNode->left)
				st.push(pNode->left);
			//若该结点的右结点不为空，则将其右结点入栈
			if (pNode->right)
				st.push(pNode->right);
		}
		return pRoot; //返回根结点
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