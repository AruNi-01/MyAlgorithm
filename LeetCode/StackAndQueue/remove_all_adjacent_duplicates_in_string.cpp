/*
 * @Descripttion: 1047. 删除字符串中的所有相邻重复项
 * @Author: AruNi
 * @Date: 2022-04-04 23:33:44
 */

/*
题目：
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

示例：
输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。
之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
*/

/*
栈：和括号匹配题类似，把字符串按顺序放入栈中，如果遇到相同的，就将栈弹出，当前元素也不入栈了
    这样最后栈里剩下的元素都是不相同的元素了；最后将栈弹出，反转字符串即可(因为栈先进后出)
*/
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c: s) {
            //当遍历第一个字符时，栈为空
            if (st.empty() || c != st.top()) {
                st.push(c);
            } else {
                st.pop();
            }
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};