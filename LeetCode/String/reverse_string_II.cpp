/*
 * @Descripttion: 541. 反转字符串 II
 * @Author: AruNi
 * @Date: 2022-04-02 22:46:53
 */

/*
题目：
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
    如果剩余字符少于 k 个，则将剩余字符全部反转。
    如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例 1：
输入：s = "abcdefg", k = 2
输出："bacdfeg"

示例 2：
输入：s = "abcd", k = 2
输出："bacd"
*/

//正常模拟，本题侧重点不在于反转，可以使用reverse函数
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            //每隔2k个字符反转前k个字符
            //先反转再进行+2k，包括了 剩余字符小于2k但大于或等于k个，则反转前k个字符，其余字符保持原样
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            //剩下的字符少于k个，将字符全部反转
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};

//自己实现reverse版本
class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            //每隔2k个字符反转前k个字符
            if (i + k <= s.size()) {
                reverse(s, i, i + k - 1);
                continue;
            }
            //剩下的字符少于k个，将字符全部反转
            reverse(s, i, s.size() - 1);
        }
        return s;
    }
};
