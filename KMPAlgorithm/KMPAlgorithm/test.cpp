#include <iostream>
#include <vector>
#include <string>
using namespace std;
int searchNeedle(string haystack, string needle) {
    int hLen = haystack.size(), nLen = needle.size();
    if (hLen < nLen) //�ı�������С��ģʽ�����ȣ�ƥ��ʧ��
        return -1;
    for (int i = 0; i <= hLen - nLen; i++) { //����ö���ı����еĸ����ַ�����Ϊƥ�����ʼλ��
        if (haystack[i] == needle[0]) { //��ǰ�ַ���ģʽ����0���ַ�ƥ�䣬����ƥ��
            int hCur = i, nCur = 0;
            while (hCur < hLen && nCur < nLen && haystack[hCur] == needle[nCur]) {
                hCur++;
                nCur++;
            }
            if (nCur == nLen) //ģʽ��ƥ����ϣ���iλ��Ϊ��ʼλ��ƥ��ɹ�
                return i;
        }
    }
    return -1; //ƥ��ʧ��
}
int main() {

	return 0;
}
