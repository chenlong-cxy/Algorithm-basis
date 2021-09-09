#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		for (size_t i = 0; i < array.size(); i++)
//		{
//			if (array[i] % 2 == 0)
//			{
//				size_t j = i + 1;
//				while (j < array.size() && array[j] % 2 == 0)
//				{
//					j++;
//				}
//				if (j == array.size())
//					return;
//				int temp = array[j];
//				for (size_t k = j; k > i; k--)
//				{
//					array[k] = array[k - 1];
//				}
//				array[i] = temp;
//			}
//		}
//	}
//};

//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		size_t left = 0, right = array.size() - 1;
//		while (left < right)
//		{
//			while (left < right&&array[left] % 2 == 1) //left向右找偶数
//			{
//				left++;
//			}
//			while (left < right&&array[right] % 2 == 0) //right向左找奇数
//			{
//				right--;
//			}
//			swap(array[left], array[right]); //交换left和right索引的元素
//		}
//	}
//};

//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		vector<int> temp; //辅助容器
//		//遍历数组将奇数尾插到temp容器当中
//		for (auto e : array)
//		{
//			if (e & 1) //是奇数
//				temp.push_back(e);
//		}
//		//遍历数组将偶数尾插到temp容器当中
//		for (auto e : array)
//		{
//			if (!(e & 1)) //是偶数
//				temp.push_back(e);
//		}
//		array = temp; //将temp容器赋值给array容器
//	}
//};

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int i = 0; //标记已经放好的奇数序列的后一个位置
		for (int j = 0; j < array.size(); j++)
		{
			if (array[j] & 1) //找到奇数
			{
				int temp = array[j]; //先将这个奇数存储到temp变量当中
				//将变量i和变量j之间的数统一向后移动一位
				for (int k = j - 1; k >= i; k--)
				{
					array[k + 1] = array[k];
				}
				array[i] = temp; //将temp变量当中存储的奇数放到i的位置
				i++; //更新i的位置
			}
		}
	}
};

int main()
{
	vector<int> array{1, 2, 3, 4, 5, 6};
	Solution().reOrderArray(array);
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}