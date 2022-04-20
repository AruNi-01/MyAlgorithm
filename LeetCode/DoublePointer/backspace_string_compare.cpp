/*
 * @Descripttion: 844. 比较含退格的字符串
 * @Author: AruNi
 * @Date: 2022-03-20 22:59:45
 */

/*
题目：
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。

示例 1：
输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。

示例 2：
输入：s = "ab##", t = "c#d#"
输出：true
解释：s 和 t 都会变成 ""。

示例 3：
输入：s = "a#c", t = "b"
输出：false
解释：s 会变成 "c"，但 t 仍然是 "b"。
*/

//伪栈法
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return getString(s) == getString(t);
    }

private:
    string getString(const string& str) {
        //把string当成栈，利用栈先进后出的特点，遇到一个#就压一个最近拼接的字符出来
        string s;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != '#') {
                s +=str[i];
            } else if (!s.empty()){     //当栈不为空的时候才将值压出来，避免压空栈
                s.pop_back();
            }
        }
        return s;
    }
};


//从后往前双指针法
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int sSkipNum = 0; // 记录S的#数量
        int tSkipNum = 0; // 记录T的#数量
        int i = S.size() - 1;
        int j = T.size() - 1;
        while (1) {
            while (i >= 0) { // 从后向前，消除S的#
                if (S[i] == '#') sSkipNum++;
                else {
                    if (sSkipNum > 0) sSkipNum--;
                    else break;
                }
                i--;
            }
            while (j >= 0) { // 从后向前，消除T的#
                if (T[j] == '#') tSkipNum++;
                else {
                    if (tSkipNum > 0) tSkipNum--;
                    else break;
                }
                j--;
            }
            // 后半部分#消除完了，接下来比较S[i] != T[j]
            if (i < 0 || j < 0) break; // S 或者T 遍历到头了
            if (S[i] != T[j]) return false;
            i--;j--;
        }
        // 说明S和T同时遍历完毕
        if (i == -1 && j == -1) return true;
        return false;
    }
};