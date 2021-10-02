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
		if (pre.empty() || vin.empty() || pre.size() != vin.size()) //ǰ���������Ϊ�գ������������Ϊ�գ�ǰ������������������ָ�����ͬ����Ƿ�
			return nullptr;
		//�ݹ鴴�������������ظ�����ַ
		return _reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
	TreeNode* _reConstructBinaryTree(vector<int> pre, int PreStart, int PreEnd, vector<int> vin, int VinStart, int VinEnd)
	{
		//����ǰ��������л�����������в����ڣ��ݹ����������
		if (PreStart > PreEnd || VinStart > VinEnd)
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(pre[PreStart]); //���������
		for (int i = VinStart; i <= VinEnd; i++)
		{
			if (vin[i] == pre[PreStart]) //�������������е����ҵ������
			{
				//�ݹ鴴��������
				root->left = _reConstructBinaryTree(pre, PreStart + 1, PreStart + i - VinStart, vin, VinStart, i - 1);
				//�ݹ鴴��������
				root->right = _reConstructBinaryTree(pre, PreStart + i - VinStart + 1, PreEnd, vin, i + 1, VinEnd);
				break;
			}
		}
		return root; //���ظ�����ַ
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