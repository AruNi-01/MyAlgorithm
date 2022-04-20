/*
 * @Descripttion: 242. 有效的字母异位词
 * @Author: AruNi
 * @Date: 2022-03-29 22:16:33
 */

/*
题目：
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        //记录s中各字母出现的次数
        //并不需要记住字符的ASCII，只要求出一个相对数值就可以了
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        //若t中有s中的字母，则该字母的数量--
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        //遍历26个字母；若有一个字母的数量不为0，则证明s和t不是字母异位词
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) return false;
        }
        return true;
    }
};