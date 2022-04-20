/*
 * @Descripttion: 383. 赎金信
 * @Author: AruNi
 * @Date: 2022-03-29 22:19:54
 */

/*
题目：
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次。

示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        //先将提供的各字符数量统计出来
        for (int i = 0; i < magazine.size(); i++) {
            record[magazine[i] - 'a']++;
        }
        //边减边判断所需字符的数量是否够
        for (int i = 0; i < ransomNote.size(); i++) {
            record[ransomNote[i] - 'a']--;
            //小于0说明需要的字符大于提供的字符，直接返回false
            if (record[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};