/*
 * @Descripttion: 438. 找到字符串中所有字母异位词
 * @Author: AruNi
 * @Date: 2022-03-30 22:37:31
 */

/*
题目：
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

示例 1:
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

示例 2:
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
*/

//滑动窗口法
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int pro[26] = {0};
        int ned[26] = {0};
        //记录需要的字符
        for (int i = 0; i < p.size(); i++) {
            ned[p[i] - 'a']++;
        }

        int fast = 0;
        int slow = 0;
        while (fast < s.size()) {
            pro[s[fast] - 'a']++;

            //当提供的字符大于所需字符时，移动慢指针，改变窗口的范围
            while (pro[s[fast] - 'a'] > ned[s[fast] - 'a']) {
                pro[s[slow] - 'a']--;       //因为下面要移动慢指针，所以减去一个对应提供的字符
                slow++;
            }

            //当窗口大小满足所需字符大小时，其实此时窗口内的字符必定是异位词，因为上面的while循环会剔除不满足的情况
            if (fast - slow + 1 == p.size()) {
                result.push_back(slow);
            }

            fast++;
        }
        return result;
    }
};