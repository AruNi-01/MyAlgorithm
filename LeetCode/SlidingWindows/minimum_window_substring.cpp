/*
 * @Descripttion: 76. 最小覆盖子串
 * @Author: AruNi
 * @Date: 2022-03-27 10:31:26
 */

/*
题目：
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：
    对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
    如果 s 中存在这样的子串，我们保证它是唯一的答案。

示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

示例 2：
输入：s = "a", t = "a"
输出："a"

示例 3:
输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
*/

/*
滑动窗口：1. 将数组中的字符和其频数用一个int数组need保存起来，字符利用ASCII码对应
         2. 定义一个count用于存储目标数组的长度，让有边界遍历s字符串，当寻找need中需要的字符，count-1
         3. 当count=0时，说明此时窗口中包含了我们需要的所有字符
         4. 去掉冗余的字符（不需要的字符/重复的需要字符），让左边界右移
         5. 更新有效区间的最小值
         6. 得到最小区间后，继续让左边界右移，接着重复以上步骤去查找是否有更短的子串
*/
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || s.size() == 0 || t.empty() || t.size() == 0) {
            return "";
        }

        //vector<int> need(128, 0);
        int need[128] = {0};        //记录字符
        //保存需要的字符个数，例如：t[1] = A, 则need[65]++
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }

        int left = 0;
        int right = 0;
        int size = INT_MAX;     //有效窗口大小
        int count = t.size();   //需要的字符个数
        int start = 0;          //有效窗口的最左元素的下标
        
        while (right < s.size()) {
            //查找到了我们需要的字符，对应count-1
            if (need[s[right]] > 0) {
                count--;
            }

            //将遍历到的字符在need中-1；
            //若是需要的字符则会-1，出现多余的会变成负数；若是无关字符则会变成负数
            need[s[right]]--;
            
            //窗口中已经包含了所有需要的字符
            if (count == 0) {
                //去掉冗余的字符，缩小区间；有两种情况
                //1：无关字符；2：需要的重复字符（即需要的字符为负数的情况）
                while (left < right && need[s[left]] < 0) {     //字符频数等于0表示需要的字符刚刚好或者没有了无关字符
                    need[s[left]]++;
                    left++;
                }
                //更新有效区间的最小值
                if (right - left + 1 < size) {
                    size = right - left + 1;
                    start = left;
                }
                //将左边界右移，继续寻找后面是否有更短的子串
                //左边界右移后，减少了一位需要的字符，所以need中该元素的值和count都需要+1
                //注意：need中该元素的值++后再执行left++
                need[s[left]]++;
                left++;
                count++;
            }
            //右边界右移
            right++;
        }
        //从s字符串中截取start位置开始的size个字符
        return size == INT_MAX? "": s.substr(start, size);
    }
};