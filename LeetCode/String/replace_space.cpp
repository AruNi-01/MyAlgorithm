/*
 * @Descripttion: 剑指 Offer 05. 替换空格
 * @Author: AruNi
 * @Date: 2022-04-02 23:23:54
 */

/*
题目：
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."
*/

/*双指针法：首先扩充数组到每个空格替换成"%20"之后的大小。然后从后向前替换空格，i指针指向新数组的最后，
j指针指向旧数组的最后，若j没有遇到空格，则直接将j位置的值赋给i位置，若j遇到空格，则i位置反向填%20
为什么要从后向前填充？
从前向后填充就是$O(n^2)$的算法了，因为每次添加元素都要将添加元素之后的所有元素向后移动。
这么做有两个好处：
    1. 不用申请新数组。
    2. 从后向前填充元素，避免了从前先后填充元素要来的 每次添加元素都要将添加元素之后的所有元素向后移动。
*/        
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;      //统计空格数量
        int sOldSize = s.size();
        for (int i = 0; i < sOldSize; i++) {
            if (s[i] == ' ') count++;
        }
        //扩充字符串s的大小，原来的空格占一个字符，%20占三个，所以count*2
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();
        //从后往前替换空格
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                //这里只用-2，因为for循环还要减
                i -= 2;
            }
        }
        return s;
    }
};