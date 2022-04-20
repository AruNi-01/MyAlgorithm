/*
 * @Descripttion: 151. 颠倒字符串中的单词
 * @Author: AruNi
 * @Date: 2022-04-02 23:45:37
 */

/*
题目：
给你一个字符串s，颠倒字符串中单词的顺序。单词是由非空格字符组成的字符串。
s中使用至少一个空格将字符串中的单词分隔开。返回单词顺序颠倒且单词之间用单个空格连接的结果字符串。
注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，
单词间应当仅用单个空格分隔，且不包含任何额外的空格。

示例 1：
输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：
输入：s = "  hello world  "
输出："world hello"
解释：颠倒后的字符串中不能存在前导空格和尾随空格。

示例 3：
输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，颠倒后的字符串需要将单词间的空格减少到仅有一个。
*/

/*思路：使用整体反转+局部反转就可以实现反转单词顺序的目的。
        1.移除多余空格
        2.将整个字符串反转
        3.将每个单词反转
    注意：移除多余空格如果直接用for遍历，遇到空格就erase，这样移除空格的时间复杂度是O(n^2)，
    因为erase操作的时间复杂度就是O(n)；
    
    采用双指针法：fast走得快，slow走得慢，slow就标记移除多余空格后新字符串的长度，
                最后resize（重新设置）一下字符串的大小，就可以做到O(n)的时间复杂度
*/
class Solution {
public:
    //移除多余的空格
    void removeExtraSpaces(string& s) {
        int slow = 0, fast = 0;
        //移除字符串前面的空格，将fast移动到第一个字母的位置
        while (s.size() > 0 && fast < s.size() && s[fast] == ' ') {
            fast++;
        }
        for (; fast < s.size(); fast++) {
            //移除字符串中间部分冗余空格
            if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ') {
                continue;
            } else {
                //若中间没有空格或者只有一个空格，则更新slow指针位置的值
                s[slow++] = s[fast];
            }
        }
        //移除字符串尾部的空格，当最后一个字符是空格时，s的长度就是slow-1；否则就是slow
        if (slow - 1 > 0 && s[slow - 1] == ' ') {
            s.resize(slow - 1);
        } else {
            s.resize(slow);
        }
    }

    //自定义反转字符串（左闭右闭）方法，也是双指针法；也可以使用库函数
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        //反转每个单词
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            //查找单词之间的空格，将j移动到空格的位置
            while (j < s.size() && s[j] != ' ') j++;
            reverse(s, i, j - 1);
            i = j;      //将i移动到空格位置，for循环++后，开始下一轮找空格
        }
        return s;
    }
};