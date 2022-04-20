/*
 * @Descripttion: 20. 有效的括号
 * @Author: AruNi
 * @Date: 2022-04-04 23:04:25
 */

/*
题目：
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

示例 4：
输入：s = "([)]"
输出：false

示例 5：
输入：s = "{[]}"
输出：true
*/

/*栈：遍历字符串，将左括号对应的右括号全部压入栈中，例如遇到'{'就将'}'压入栈，
     当遍历到右括号时，就从栈中弹出该括号，因为栈的先进后出，所有括号的匹配
     肯定是满足就近原则的。
     1.当遍历过程中栈为空了，则说明右括号有多余的，return false
     2.当遍历过程中发现栈中没有匹配的字符，直接return false
     3.当遍历完字符串了，栈还不为空，说明左括号有多余的，return false
*/

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '{') st.push('}');
            else if (st.empty() || st.top() != s[i]) return false;  //对应情况1，2
            else st.pop();      //此时栈顶的元素与s[i]相等，弹出该元素
        }
        return st.empty();      //若栈为空，则说明括号刚好匹配完，若栈不为空，则对应情况3
    }
};