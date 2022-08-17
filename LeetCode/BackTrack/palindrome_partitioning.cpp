/*
 * @Descripttion: 
 * @Author: AruNi_Lu
 * @Date: 2022-05-13 12:38:05
 */
// 131. 分割回文串

/*
题目：
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。

示例 1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]

示例 2：
输入：s = "a"
输出：[["a"]]
*/

// 思路：1.切割问题，有不同的切割方式；2.判断是否回文
class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;    // 存放是回文的子串
    // startIndex 记录切割第几个字符了，因为切割过的地方，不能重复切割
    void backtrack(const string& s, int startIndex) {
        // 终止条件：起始位置大于s的大小，说明已经递归到s字符串最后的位置了，找到了一组分割方案
        if (startIndex >= s.size()) {   // startIndex从0开始，所以>=
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {   // 是回文子串
                // 获取[startIndex, i]在s中的子串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {    // 如果不是则直接跳过
                continue;
            }
            backtrack(s, i + 1);    // 寻找下一层i+1为起始位置的子串
            path.pop_back();    // 回溯，弹出本次已经填入的子串
        }
    }

    // 采用双指针法判断是否是回文子串：
    // 一个指针从前向后，一个指针从后先前，如果前后指针所指向的元素是相等的，就是回文字符串了。
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;
    }
};