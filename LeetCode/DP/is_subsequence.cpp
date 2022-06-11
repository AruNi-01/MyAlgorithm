/*
 * @Descripttion: 392. 判断子序列
 * @Author: AruNi_Lu
 * @Date: 2022-06-11 14:56:00
 */


/*
题目：
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变
剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
进阶：
如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，
你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

示例 1：
输入：s = "abc", t = "ahbgdc"
输出：true

示例 2：
输入：s = "axc", t = "ahbgdc"
输出：false
*/

/*
双指针法：
    定义两个指针，一个指向字符串s，另一个指向字符串t。
    然后固定s，遍历t直到找到s[index1]=t[index2]，此时才将1指针++。
    若最后1指针的长度等于字符串s的长度，则说明s为t的子序列。
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        int index1 = 0;
        for (int index2 = 0; index2 < t.size(); index2++) {
            if (s[index1] == t[index2]) index1++;
        }
        return index1 == s.size() ? true : false;
    }
};

/*
DP法：

*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
    }
};
