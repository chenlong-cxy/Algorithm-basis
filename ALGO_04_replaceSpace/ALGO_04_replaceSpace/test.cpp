#include <iostream>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0; //记录字符串中空格的个数
		//遍历字符串，统计字符串当中的空格数
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
				count++;
		}
		//计算替换后字符串的新长度
		int newlength = length + 2 * count;
		//从后向前对字符串进行填充
		while (newlength >= 0)
		{
			if (str[length] == ' ') //遇到的是空格，则从后往前填充字符'0'，'2'，'%'
			{
				str[newlength--] = '0';
				str[newlength--] = '2';
				str[newlength--] = '%';
			}
			else //遇到的不是空格，则将遍历到的字符从后往前进行填充
			{
				str[newlength--] = str[length];
			}
			length--;
		}
	}
};
int main()
{
	char arr[] = "We Are Happy\0      ";
	cout << sizeof(arr) / sizeof(char) << endl;
	cout << strlen(arr) << endl;
	Solution().replaceSpace(arr, strlen(arr));
	cout << arr << endl;
	return 0;
}