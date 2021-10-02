#include <iostream>
#include <vector>
using namespace std;

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode
{
	TreeNode(int x)
	:val(x)
	, left(nullptr)
	, right(nullptr)
	{}
	int val;
	TreeNode* left;
	TreeNode* right;
};
void Pre(TreeNode* root)
{
	if (root == nullptr)
		return;
	printf("%d ", root->val);
	Pre(root->left);
	Pre(root->right);
}
void Vin(TreeNode* root)
{
	if (root == nullptr)
		return;
	Vin(root->left);
	printf("%d ", root->val);
	Vin(root->right);
}
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty() || pre.size() != vin.size()) //前序遍历序列为空，中序遍历序列为空，前序中序遍历序列中数字个数不同，则非法
			return nullptr;
		//递归创建二叉树并返回根结点地址
		return _reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
	TreeNode* _reConstructBinaryTree(vector<int> pre, int PreStart, int PreEnd, vector<int> vin, int VinStart, int VinEnd)
	{
		//树的前序遍历序列或中序遍历序列不存在（递归结束条件）
		if (PreStart > PreEnd || VinStart > VinEnd)
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(pre[PreStart]); //创建根结点
		for (int i = VinStart; i <= VinEnd; i++)
		{
			if (vin[i] == pre[PreStart]) //在所给中序序列当中找到根结点
			{
				//递归创建左子树
				root->left = _reConstructBinaryTree(pre, PreStart + 1, PreStart + i - VinStart, vin, VinStart, i - 1);
				//递归创建右子树
				root->right = _reConstructBinaryTree(pre, PreStart + i - VinStart + 1, PreEnd, vin, i + 1, VinEnd);
				break;
			}
		}
		return root; //返回根结点地址
	}
};

int main()
{
	vector<int> pre{ 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin{ 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode* root = Solution().reConstructBinaryTree(pre, vin);
	Pre(root);
	cout << endl;
	Vin(root);
	return 0;
}