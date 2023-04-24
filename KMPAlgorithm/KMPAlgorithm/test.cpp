#include <iostream>
#include <vector>
#include <string>
using namespace std;
//int searchNeedle(string haystack, string needle) {
//    int hLen = haystack.size(), nLen = needle.size();
//    if (hLen < nLen) //�ı�������С��ģʽ�����ȣ�ƥ��ʧ��
//        return -1;
//    for (int i = 0; i <= hLen - nLen; i++) { //����ö���ı����еĸ����ַ�����Ϊƥ�����ʼλ��
//        if (haystack[i] == needle[0]) { //��ǰ�ַ���ģʽ����0���ַ�ƥ�䣬����ƥ��
//            int hCur = i, nCur = 0;
//            while (hCur < hLen && nCur < nLen && haystack[hCur] == needle[nCur]) {
//                hCur++;
//                nCur++;
//            }
//            if (nCur == nLen) //ģʽ��ƥ����ϣ���iλ��Ϊ��ʼλ��ƥ��ɹ�
//                return i;
//        }
//    }
//    return -1; //ƥ��ʧ��
//}

/* KMP�㷨: �������ַ�����ƥ��ʱ�������ͷ��ȥ��ƥ�� */
//����ģʽ������ǰ׺��
vector<int> getNext(const string& needle) {
    //j: ָ��ǰ׺ĩβλ�ã�ǰ׺�ĳ��ȣ�
    //i: ָ���׺ĩβλ��
    int n = needle.size();
    vector<int> next(n);
    next[0] = 0; //���±�Ϊ0���ַ���β���ַ�������ͬǰ��׺����Ϊ0
    int j = 0; //ָ��ǰ׺ĩβλ��
    for (int i = 1; i < n; i++) { //i��1��ʼ,next[0]�ѱ���ʼ��
        while (j > 0 && needle[j] != needle[i]) { //ǰ��׺ĩβ����ͬ,ǰ׺λ����ǰ����
            j = next[j - 1]; //j���˵����±�Ϊj-1���ַ���β���ַ��������ͬǰ��׺��ǰ׺����һ��λ��
        }
        if (needle[j] == needle[i]) { //ǰ��׺ĩβ��ͬ
            j++; //j���ƺ����ֵ���Ǵ�ʱǰ׺�ĳ���
        }
        next[i] = j; //���±�Ϊi���ַ���β���ַ�������ͬǰ��׺�ĳ��ȣ�Ҳ��ǰ׺����һ��λ�õ��±꣩
    }
    return next; //����ǰ׺��
}

int searchNeedle(string haystack, string needle) {
    //j: ָ��ģʽ������һ�����Ƚϵ��ַ�
    //i: ָ���ı�������һ�����Ƚϵ��ַ�
    int n = needle.size();
    if (n == 0) //ģʽ��Ϊ�մ�
        return 0;
    vector<int> next = getNext(needle); //����ģʽ������ǰ׺��
    int j = 0; //ָ��ģʽ������һ�����Ƚϵ��ַ�
    for (int i = 0; i < haystack.size(); i++) { //ָ���ı�������һ�����Ƚϵ��ַ�
        while (j > 0 && needle[j] != haystack[i]) { //��ǰ�ַ���ƥ��,ָ��ģʽ����ָ����ǰ���ˣ�����Ѱ��ƥ��λ�ã�
            j = next[j - 1]; //���˵����±�Ϊj-1���ַ���β���ַ��������ͬǰ��׺��ǰ׺����һ��λ��
        }
        if (needle[j] == haystack[i]) { //��ǰ�ַ�ƥ��
            j++; //ָ��ģʽ����ָ�����
            if (j == n) //j�Ѿ�����ģʽ��ĩβ,ƥ�����
                return i - n + 1; //�����ı����е���ʼƥ���±�
        }
    }
    return -1; //ƥ��ʧ��,�ı�����û�г��ֹ�ģʽ��
}

//ʱ�临�Ӷ�: O(n+m)
//nextǰ׺��: �������˵�,����¼��ģʽ�����ı�����ƥ���ʱ��,ģʽ��Ӧ�ô����￪ʼ����ƥ��
//nextǰ׺��: ͳ�����Ը���λ��Ϊ�յ���ַ��������ͬǰ��׺�ĳ���

int main() {
    cout << searchNeedle("aabaabaafa", "aabaaf") << endl;
	return 0;
}

