/*
 * @Descripttion: 96. 不同的二叉搜索树
 * @Author: AruNi
 * @Date: 2022-05-28 19:49:35
 */

/*
题目：
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 
二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

示例 1：
1    1        2          3      3
 \    \      / \        /      /
  3    2    1   3      2      1
 /      \             /        \ 
2        3           1          2
输入：n = 3
输出：5

示例 2：
输入：n = 1
输出：1
*/


/*
分析：
n=1时：    n=2时：
  1      1      2
          \    /
           2  1

n=1时有1棵树，n=2时有2棵树，这是很直观的。
当n=3时：
1    1        2          3      3
 \    \      / \        /      /
  3    2    1   3      2      1
 /      \             /        \ 
2        3           1          2
通过上面的情况分析：
当1为头结点时，子树的布局和n=2相同。
当3为头结点时，子树的布局也是和n=2相同。
当2为头结点时，子树的布局和n=1相同。

通过分析就找到了重叠子问题了，其实也就是发现可以通过dp[1] 和 dp[2] 
来推导出来dp[3]的某种方式。

dp[3]，就是 元素1为头结点搜索树的数量 + 元素2为头结点搜索树的数量 + 元素3为头结点搜索树的数量
元素1为头结点搜索树的数量 = 右子树有2个元素的搜索树数量 * 左子树有0个元素的搜索树数量
元素2为头结点搜索树的数量 = 右子树有1个元素的搜索树数量 * 左子树有1个元素的搜索树数量
元素3为头结点搜索树的数量 = 右子树有0个元素的搜索树数量 * 左子树有2个元素的搜索树数量
有2个元素的搜索树数量就是dp[2]。
有1个元素的搜索树数量就是dp[1]。
有0个元素的搜索树数量就是dp[0]。
所以dp[3] = dp[2] * dp[0] + dp[1] * dp[1] + dp[0] * dp[2]
如图：https://img-blog.csdnimg.cn/20210107093226241.png

DP五部曲：
    1. 确定dp数组和其下标的含义
        dp[i]：1到i为节点组成的二叉搜索树的个数为dp[i]个
        也可以理解是i的不同元素节点组成的二叉搜索树的个数为dp[i]
    2. 确定递推公式
        在上面的分析中，其实已经看出其递推关系， dp[i] += dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量]
        j相当于是头结点的元素，从1遍历到i为止。
        所以递推公式：dp[i] += dp[j - 1] * dp[i - j]; ，j-1 为j为头结点左子树节点数量，i-j 为以j为头结点右子树节点数量
    3. dp数组的初始化
        初始化，只需要初始化dp[0]就可以了，推导的基础，都是dp[0]。
        从定义上来讲，空节点也是一棵二叉树，也是一棵二叉搜索树，这是可以说得通的。
        从递归公式上来讲，dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量] 
        中，即使以j为头结点左子树节点数量为0，也需要dp[以j为头结点左子树节点数量] = 1， 否则乘法的结果就都变成0了。
        所以初始化dp[0] = 1
    4. 确定遍历顺序
        首先一定是遍历节点数，从递归公式：dp[i] += dp[j - 1] * dp[i - j]可以看出，节点数为i的状态是依靠 i之前节点数的状态。
        那么遍历i里面每一个数作为头结点的状态，用j来遍历。
        代码如下：
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
    5. 举例推导dp数组
        n=5时的dp数组状态如下：
        下标i：0    1   2   3   4   5
        dp[i]:1    1   2   5   14  42
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // 对于第i个节点，需要考虑1作为根节点直到i作为根节点的情况，所以需要累加
                // 一共i个节点，对于根节点j时,左子树的节点个数为j-1，右子树的节点个数为i-j
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
