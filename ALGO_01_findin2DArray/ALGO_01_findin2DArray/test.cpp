#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		for (int i = 0; i < array.size(); i++)
		{
			for (int j = 0; j < array[i].size(); j++)
			{
				if (target == array[i][j])
					return true; //�ҵ��˷���true
			}
		}
		return false; //û�ҵ�����false
	}
};

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int i = 0, j = array[0].size() - 1;
		while (i < array.size() && j >= 0)
		{
			if (target > array[i][j]) //���������ֱȸ�Ԫ�ش�
			{
				i++; //�����ڸ��н��в�����
			}
			else if (target < array[i][j]) //���������ֱȸ�Ԫ��С
			{
				j--; //�����ڸ��н��в�����
			}
			else
			{
				return true; //�ҵ��˷���true
			}
		}
		return false; //�������������δ�ҵ�����false
	}
};