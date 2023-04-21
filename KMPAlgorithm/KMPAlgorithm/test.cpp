#include <iostream>
#include <vector>
#include <string>
using namespace std;
//int searchNeedle(string haystack, string needle) {
//    int hLen = haystack.size(), nLen = needle.size();
//    if (hLen < nLen) //文本串长度小于模式串长度，匹配失败
//        return -1;
//    for (int i = 0; i <= hLen - nLen; i++) { //依次枚举文本串中的各个字符来作为匹配的起始位置
//        if (haystack[i] == needle[0]) { //当前字符与模式串第0个字符匹配，则尝试匹配
//            int hCur = i, nCur = 0;
//            while (hCur < hLen && nCur < nLen && haystack[hCur] == needle[nCur]) {
//                hCur++;
//                nCur++;
//            }
//            if (nCur == nLen) //模式串匹配完毕，以i位置为起始位置匹配成功
//                return i;
//        }
//    }
//    return -1; //匹配失败
//}

/* KMP算法: 当出现字符串不匹配时，避免从头再去做匹配 */
//根据模式串生成前缀表
vector<int> getNext(const string& needle) {
    //j: 指向前缀末尾位置（前缀的长度）
    //i: 指向后缀末尾位置
    int n = needle.size();
    vector<int> next(n);
    next[0] = 0; //以第0个字符结尾的字符串的相同前后缀长度为0
    int j = 0; //前缀末尾位置
    for (int i = 1; i < n; i++) { //
        while (j > 0 && needle[j] != needle[i]) { //前后缀末尾不相同,前缀位置向前回退
            j = next[j - 1]; //j回退到之前的子串的相同前后缀的前缀的下一个位置
        }
        if (needle[j] == needle[i]) { //前后缀末尾相同,前缀位置后移
            j++; //j后移后的数值也是此时前缀的长度
        }
        next[i] = j; //以i为结尾的字符串的相同前后缀的长度（也是前缀的下一个位置的下标）
    }
    return next;
}
int searchNeedle(string haystack, string needle) {
    //j: 遍历模式串
    //i: 遍历文本串
    int n = needle.size();
    if (n == 0)
        return 0;
    vector<int> next = getNext(needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); i++) {
        while (j > 0 && needle[j] != haystack[i]) { //当前字符不匹配,j向前回退（重新寻找匹配位置）
            j = next[j - 1];
        }
        if (needle[j] == haystack[i]) { //当前字符匹配,j后移
            j++;
            if (j == n) //j已经到达模式串末尾,匹配完毕
                return i - n + 1;
        }
    }
    return -1;
}

//时间复杂度: O(n+m)
//next前缀表: 用来回退的,它记录了模式串与文本串不匹配的时候,模式串应该从哪里开始重新匹配
//next前缀表: 统计了以各个位置为终点的字符串的最长相同前后缀的长度

int main() {
    cout << searchNeedle("aabaabaafa", "aabaaf") << endl;
	return 0;
}
