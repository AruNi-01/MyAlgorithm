/*
 * @Descripttion: 72. 编辑距离
 * @Author: AruNi_Lu
 * @Date: 2022-06-14 16:08:02
 */

/*
题目：
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
你可以对一个单词进行如下三种操作：
    插入一个字符
    删除一个字符
    替换一个字符

示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/

/*
编辑距离是用动规来解决的经典题目，这道题目看上去好像很复杂，但用动规可以很巧妙的算出最少编辑距离。
DP五部曲：
    1. 确定dp数组和其下标含义
        dp[i][j]：以下标i-1为结尾的字符串word1，和以下标j-1为结尾的字符串word2，最近编辑距离为dp[i][j]。
    2. 确定递推公式
        在确定递推公式之前，首先要考虑清除编辑的几种操作：
        if (word1[i - 1] == word2[j - 1]) {
            不操作
        } else {
            增
            删
            换
        }
        if (word1[i - 1] == word2[j - 1]) 那么说明不用任何编辑，dp[i][j]无需改变，
        就应该是 dp[i - 1][j - 1]，即dp[i][j] = dp[i - 1][j - 1];

        if (word1[i - 1] != word2[j - 1])，此时就需要编辑了，如何编辑呢？
        ·操作一：word1删除一个元素，那么就是以下标i-2为结尾的word1与j-1为结尾的word2的最近编辑距离+1（1个编辑）
                即：dp[i][j] = dp[i - 1][j] + 1;
        ·操作二：word2删除一个元素，那么就是以下标i-1为结尾的word1与j-2为结尾的word2的最近编辑距离+1（1个编辑）
                即：dp[i][j] = dp[i][j - 1] + 1;
        怎么都是删除元素，添加元素去哪了？？
        word2添加一个元素，相当于word1删除一个元素，例如 word1="ad"，word2="a"，word1删除元素'd'和word2添加一个元素'd'，
        变成word1="a"，word2="ad"，最终的操作数是一样的！如下：
            word1删除一个字符 => dp[i][j]=dp[i-1][j]+1
            word2插入一个字符 => dp[i][j]=dp[i-1][j]+1
            word2删除一个字符 => dp[i][j]=dp[i][j-1]+1
            word1插入一个字符 => dp[i][j]=dp[i][j-1]+1
        ·操作三：替换元素，word1替换word1[i-1]，使其与word2[j-1]相同，此时不用增加元素，
        那么下标i-2为结尾的word1与j-2为结尾的word2的最近编辑距离+1（1个替换操作）
                即：dp[i][j] = dp[i - 1][j - 1] + 1;
        word2替换字符和word1替换字符的情况一样：
        word1替换一个字符 => dp[i][j]=dp[i-1][j-1]+1
        word2替换一个字符 => dp[i][j]=dp[i-1][j-1]+1
        
        综上，当if (word1[i - 1] != word2[j - 1]) 时取最小的，
        即：dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
        递归公式代码如下：
        if (word1[i - 1] == word2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
        }
        else {
            dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
        }
    3. dp数组的初始化
        dp数组的初始化要从dp的定义入手，dp[i][0] 和 dp[0][j] 表示什么呢？
        dp[i][0] ：以下标i-1为结尾的字符串word1，和空字符串word2，最近编辑距离为dp[i][0]。
        那么dp[i][0]就应该是i，对word1里的元素全部做删除操作，即：dp[i][0] = i;
        同理dp[0][j] = j;
        所以C++代码如下：
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
    4. 确定遍历顺序
        从如下四个递推公式：
            dp[i][j] = dp[i - 1][j - 1]
            dp[i][j] = dp[i - 1][j - 1] + 1
            dp[i][j] = dp[i][j - 1] + 1
            dp[i][j] = dp[i - 1][j] + 1
        可以看出dp[i][j]是依赖左方，上方和左上方元素的，如下：
        dp[i-1][j-1]    dp[i-1][j]
        dp[i][j-1]      dp[i][j]
        所以在dp矩阵中一定是从左到右从上到下去遍历。
    5. 举例推导dp数组
        以示例1为例，输入：word1 = "horse", word2 = "ros"为例，dp矩阵状态如图：https://img-blog.csdnimg.cn/20210114162132300.jpg
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
