#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0) //数组大小为0，返回0
//			return 0;
//		int min = rotateArray[0];
//		//遍历数组寻找最小值
//		for (size_t i = 1; i < rotateArray.size(); i++)
//		{
//			if (rotateArray[i] < min)
//				min = rotateArray[i];
//		}
//		return min; //返回最小值
//	}
//};

//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0) //数组大小为0，返回0
//			return 0;
//		for (size_t i = 1; i < rotateArray.size(); i++)
//		{
//			if (rotateArray[i - 1] > rotateArray[i]) //找到前一个元素小于后一个元素的情况
//				return rotateArray[i]; //返回后者即为最小值
//		}
//		return rotateArray[0]; //数组遍历结束，返回数组的第一个元素即为最小值
//	}
//};

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0) //数组大小为0，返回0
			return 0;
		int left = 0, right = rotateArray.size() - 1;
		while (left < right)
		{
			if (rotateArray[left] < rotateArray[right]) //[left,right]区间已经是非递减序列，返回区间内第一个元素即可
				return rotateArray[left];
			int mid = left + (right - left) / 2;
			if (rotateArray[mid] < rotateArray[right]) //待查找区间缩小为[left, mid]
			{
				right = mid;
			}
			else if (rotateArray[mid] > rotateArray[right]) //待查找区间缩小为[mid+1, right]
			{
				left = mid + 1;
			}
			else //mid和right索引的元素值相同，将right往左移
			{
				right--;
			}
		}
		return rotateArray[left]; //left和right所确定的区间当中只有一个元素，返回这个元素即可
	}
};

int main()
{
	vector<int> array{3, 4, 5, 1, 2};
	cout << Solution().minNumberInRotateArray(array) << endl;
	return 0;
}