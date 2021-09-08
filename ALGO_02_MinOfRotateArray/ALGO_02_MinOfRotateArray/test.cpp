#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0) //�����СΪ0������0
//			return 0;
//		int min = rotateArray[0];
//		//��������Ѱ����Сֵ
//		for (size_t i = 1; i < rotateArray.size(); i++)
//		{
//			if (rotateArray[i] < min)
//				min = rotateArray[i];
//		}
//		return min; //������Сֵ
//	}
//};

//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0) //�����СΪ0������0
//			return 0;
//		for (size_t i = 1; i < rotateArray.size(); i++)
//		{
//			if (rotateArray[i - 1] > rotateArray[i]) //�ҵ�ǰһ��Ԫ��С�ں�һ��Ԫ�ص����
//				return rotateArray[i]; //���غ��߼�Ϊ��Сֵ
//		}
//		return rotateArray[0]; //���������������������ĵ�һ��Ԫ�ؼ�Ϊ��Сֵ
//	}
//};

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0) //�����СΪ0������0
			return 0;
		int left = 0, right = rotateArray.size() - 1;
		while (left < right)
		{
			if (rotateArray[left] < rotateArray[right]) //[left,right]�����Ѿ��Ƿǵݼ����У����������ڵ�һ��Ԫ�ؼ���
				return rotateArray[left];
			int mid = left + (right - left) / 2;
			if (rotateArray[mid] < rotateArray[right]) //������������СΪ[left, mid]
			{
				right = mid;
			}
			else if (rotateArray[mid] > rotateArray[right]) //������������СΪ[mid+1, right]
			{
				left = mid + 1;
			}
			else //mid��right������Ԫ��ֵ��ͬ����right������
			{
				right--;
			}
		}
		return rotateArray[left]; //left��right��ȷ�������䵱��ֻ��һ��Ԫ�أ��������Ԫ�ؼ���
	}
};

int main()
{
	vector<int> array{3, 4, 5, 1, 2};
	cout << Solution().minNumberInRotateArray(array) << endl;
	return 0;
}