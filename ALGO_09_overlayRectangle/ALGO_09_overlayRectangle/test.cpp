#include <iostream>
using namespace std;
class Solution {
public:
	int rectCover(int number) {
		if (number == 1 || number == 2) //f(1)=1, f(2)=2
			return number;
		int first = 1; //f(1)=1
		int second = 2; //f(2)=2
		int third = 0;
		while (number > 2) //进行number-2次计算
		{
			//f(n)=f(n-1)+f(n-2)
			third = first + second;
			first = second;
			second = third;
			number--;
		}
		return third;
	}
};
int main()
{
	cout << Solution().rectCover(3) << endl;
	return 0;
}