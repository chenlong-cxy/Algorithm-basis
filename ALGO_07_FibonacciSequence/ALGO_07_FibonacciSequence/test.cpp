#include <iostream>
#include <unordered_map>
using namespace std;
//�ݹ�
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 1 || n == 2) //fib(1)=1, fib(2)=1
			return 1;
		return Fibonacci(n - 1) + Fibonacci(n - 2); //fib(n)=fib(n-1)+fib(b-2)
	}
};
//�ݹ�+��֦
class Solution {
private:
	unordered_map<int, int> filter; //�洢�Ѿ��������쳲�������
public:
	int Fibonacci(int n) {
		if (n == 1 || n == 2) //fib(1)=1, fib(2)=1
			return 1;

		int pper = 0; //��n-2��쳲�������
		if (filter.find(n - 2) == filter.end())
		{
			//��map����û���ҵ���n-2��쳲�����������Ҫ����
			pper = Fibonacci(n - 2);
			filter.insert({ n - 2, pper });
		}
		else
		{
			//��map�����ҵ��˵�n-2��쳲���������ֱ�ӻ�ȡ
			pper = filter[n - 2];
		}

		int per = 0; //��n-1��쳲�������
		if (filter.find(n - 1) == filter.end())
		{
			//��map����û���ҵ���n-1��쳲�����������Ҫ����
			per = Fibonacci(n - 1);
			filter.insert({ n - 1, per });
		}
		else
		{
			//��map�����ҵ��˵�n-1��쳲���������ֱ�ӻ�ȡ
			per = filter[n - 1];
		}

		return pper + per; //fib(n)=fib(n-1)+fib(b-2)
	}
};
//����
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 1 || n == 2) //fib(1)=1, fib(2)=1
			return 1;
		int first = 1; //fib(1)=1
		int second = 1; //fib(2)=1
		int third = 0;
		while (n > 2) //����n-2�μ���
		{
			//fib(n)=fib(n-1)+fib(b-2)
			third = first + second;
			first = second;
			second = third;
			n--;
		}
		return third;
	}
};

int main()
{
	cout << Solution().Fibonacci(40) << endl;
	return 0;
}

//#include <stdio.h>
////void fun(int num)
////{
////	printf("%d", num / 100000);
////	num %= 100000;
////	printf("%d", num / 10000);
////	num %= 10000;
////	printf("%d,", num / 1000);
////	num %= 1000;
////	printf("%d", num / 100);
////	num %= 100;
////	printf("%d", num / 10);
////	num %= 10;
////	printf("%d", num);
////}
//void fun(int num)
//{
//	printf("%03d,%03d", num / 1000, num % 1000);
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	fun(num);
//	return 0;
//}