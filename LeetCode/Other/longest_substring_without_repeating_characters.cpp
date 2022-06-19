/*
 * @Descripttion: 3. 无重复字符的最长子串
 * @Author: AruNi_Lu
 * @Date: 2022-06-18 16:39:30
 */

/*
题目：
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

// 双指针 + Hash法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(130, 0);
        int max = 0;
        // 指针i和j对区间[i,j]进行收缩，寻找最大不重复子串
        for (int i = 0, j = 0; j < s.size(); j++) {
            hash[s[j]]++;   // 该字母对应的数量++
            while (hash[s[j]] > 1) {    //当字母的数量大于1时，说明有重复，对应的字母数量-1，i指针再右移
                hash[s[i++]]--;
            }
            // 更新最大区间值
            if (j - i + 1 > max) max = j - i + 1;
        }
        return max;
    }
};
