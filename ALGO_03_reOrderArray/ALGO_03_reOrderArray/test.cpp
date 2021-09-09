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
//			while (left < right&&array[left] % 2 == 1) //left������ż��
//			{
//				left++;
//			}
//			while (left < right&&array[right] % 2 == 0) //right����������
//			{
//				right--;
//			}
//			swap(array[left], array[right]); //����left��right������Ԫ��
//		}
//	}
//};

//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		vector<int> temp; //��������
//		//�������齫����β�嵽temp��������
//		for (auto e : array)
//		{
//			if (e & 1) //������
//				temp.push_back(e);
//		}
//		//�������齫ż��β�嵽temp��������
//		for (auto e : array)
//		{
//			if (!(e & 1)) //��ż��
//				temp.push_back(e);
//		}
//		array = temp; //��temp������ֵ��array����
//	}
//};

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int i = 0; //����Ѿ��źõ��������еĺ�һ��λ��
		for (int j = 0; j < array.size(); j++)
		{
			if (array[j] & 1) //�ҵ�����
			{
				int temp = array[j]; //�Ƚ���������洢��temp��������
				//������i�ͱ���j֮�����ͳһ����ƶ�һλ
				for (int k = j - 1; k >= i; k--)
				{
					array[k + 1] = array[k];
				}
				array[i] = temp; //��temp�������д洢�������ŵ�i��λ��
				i++; //����i��λ��
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