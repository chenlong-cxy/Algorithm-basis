#include <iostream>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0; //��¼�ַ����пո�ĸ���
		//�����ַ�����ͳ���ַ������еĿո���
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
				count++;
		}
		//�����滻���ַ������³���
		int newlength = length + 2 * count;
		//�Ӻ���ǰ���ַ����������
		while (newlength >= 0)
		{
			if (str[length] == ' ') //�������ǿո���Ӻ���ǰ����ַ�'0'��'2'��'%'
			{
				str[newlength--] = '0';
				str[newlength--] = '2';
				str[newlength--] = '%';
			}
			else //�����Ĳ��ǿո��򽫱��������ַ��Ӻ���ǰ�������
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