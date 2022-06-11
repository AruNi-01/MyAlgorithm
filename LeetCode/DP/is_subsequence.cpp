/*
 * @Descripttion: 392. 判断子序列
 * @Author: AruNi_Lu
 * @Date: 2022-06-11 14:56:00
 */


/*
题目：
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变
剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
进阶：
如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，
你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

示例 1：
输入：s = "abc", t = "ahbgdc"
输出：true

示例 2：
输入：s = "axc", t = "ahbgdc"
输出：false
*/

/*
双指针法：
    定义两个指针，一个指向字符串s，另一个指向字符串t。
    然后固定s，遍历t直到找到s[index1]=t[index2]，此时才将1指针++。
    若最后1指针的长度等于字符串s的长度，则说明s为t的子序列。
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        int index1 = 0;
        for (int index2 = 0; index2 < t.size(); index2++) {
            if (s[index1] == t[index2]) index1++;
        }
        return index1 == s.size() ? true : false;
    }
};

/*
DP法：
    1. 确定dp数组和其下标含义
        dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]。
        注意这里是判断s是否为t的子序列。即t的长度是大于等于s的。
        为啥要表示下标i-1为结尾的字符串呢，为啥不表示下标i为结尾的字符串呢？
        用i来表示也可以！但统一以下标i-1为结尾的字符串来计算，这样在下面的递归公式中会容易理解一些。
    2. 确定递推公式
        在确定递推公式的时候，首先要考虑如下两种操作，整理如下：
        if (s[i - 1] == t[j - 1])
            t中找到了一个字符在s中也出现了
        if (s[i - 1] != t[j - 1])
            相当于t要删除元素，继续匹配

        if (s[i - 1] == t[j - 1])，那么dp[i][j] = dp[i - 1][j - 1] + 1;，因为找到了一个相同的字符，
        相同子序列长度自然要在dp[i-1][j-1]的基础上加1。
        if (s[i - 1] != t[j - 1])，此时相当于t要删除元素，t如果把当前元素t[j - 1]删除，
        那么dp[i][j] 的数值就是 看s[i - 1]与 t[j - 2]的比较结果了，即：dp[i][j] = dp[i][j - 1];
    3. dp数组的初始化
        从递推公式可以看出dp[i][j]都是依赖于dp[i - 1][j - 1] 和 dp[i][j - 1]，所以dp[0][0]和dp[i][0]是一定要初始化的。
        这里已经可以发现，在定义dp[i][j]含义的时候为什么要表示以下标i-1为结尾的字符串s，
        和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]。
        因为这样的定义在dp二维矩阵中可以留出初始化的区间，如图：https://img-blog.csdnimg.cn/20210303173115966.png
        如果要是定义的dp[i][j]是以下标i为结尾的字符串s和以下标j为结尾的字符串t，初始化就比较麻烦了。
        dp[i][0] 表示以下标i-1为结尾的字符串，与空字符串的相同子序列长度，所以为0. dp[0][j]同理。
        其实这里只初始化dp[i][0]就够了，但一起初始化也方便，所以就一起操作了，代码如下：
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    4. 确定遍历顺序
        同理从递推公式可以看出dp[i][j]都是依赖于dp[i - 1][j - 1] 和 dp[i][j - 1]，那么遍历顺序也应该是从上到下，从左到右。
        如下所示：
        dp[i-1][j-1]    
        dp[i][j-1]     dp[i][j]
    5. 举例推导dp数组
        以示例一为例，输入：s = "abc", t = "ahbgdc"，dp状态转义图：https://img-blog.csdnimg.cn/2021030317364166.jpg
        dp[i][j]表示以下标i-1为结尾的字符串s和以下标j-1为结尾的字符串t 相同子序列的长度，所以如果
        dp[s.size()][t.size()] 与 字符串s的长度相同说明：s与t的最长相同子序列就是s，那么s 就是 t 的子序列。
        图中dp[s.size()][t.size()] = 3， 而s.size() 也为3。所以s是t 的子序列，返回true。
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1];
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
};
