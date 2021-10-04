#include <iostream>
using namespace std;
//递归
class Solution {
public:
	int jumpFloor(int number) {
		if (number == 0 || number == 1) //f(0)=1, f(1)=1
			return 1;
		return jumpFloor(number - 1) + jumpFloor(number - 2); //f(n)=f(n-1)+f(n-2)
	}
};
//动规
class Solution {
public:
	int jumpFloor(int number) {
		if (number == 0 || number == 1) //f(0)=1, f(1)=1
			return 1;
		int first = 1; //f(0)=1
		int second = 1; //f(1)=1
		int third = 0;
		while (number > 1) //进行number-1次计算
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
	cout << Solution().jumpFloor(5) << endl;
	return 0;
}