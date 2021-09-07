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
					return true; //找到了返回true
			}
		}
		return false; //没找到返回false
	}
};

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int i = 0, j = array[0].size() - 1;
		while (i < array.size() && j >= 0)
		{
			if (target > array[i][j]) //待查找数字比该元素大
			{
				i++; //无需在改行进行查找了
			}
			else if (target < array[i][j]) //待查找数字比该元素小
			{
				j--; //无需在该列进行查找了
			}
			else
			{
				return true; //找到了返回true
			}
		}
		return false; //数组遍历结束，未找到返回false
	}
};