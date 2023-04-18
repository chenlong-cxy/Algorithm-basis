#include <iostream>
#include <vector>
#include <string>
using namespace std;
int searchNeedle(string haystack, string needle) {
    int hLen = haystack.size(), nLen = needle.size();
    if (hLen < nLen) //文本串长度小于模式串长度，匹配失败
        return -1;
    for (int i = 0; i <= hLen - nLen; i++) { //依次枚举文本串中的各个字符来作为匹配的起始位置
        if (haystack[i] == needle[0]) { //当前字符与模式串第0个字符匹配，则尝试匹配
            int hCur = i, nCur = 0;
            while (hCur < hLen && nCur < nLen && haystack[hCur] == needle[nCur]) {
                hCur++;
                nCur++;
            }
            if (nCur == nLen) //模式串匹配完毕，以i位置为起始位置匹配成功
                return i;
        }
    }
    return -1; //匹配失败
}
int main() {

	return 0;
}
