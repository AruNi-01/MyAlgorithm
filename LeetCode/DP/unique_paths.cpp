/*
 * @Descripttion: 62. 不同路径
 * @Author: AruNi
 * @Date: 2022-05-26 16:46:56
 */


/*
题目：
一个机器人位于一个 m x n 网格的 左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的 右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
如图：https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png

示例 1：
输入：m = 3, n = 7
输出：28

示例 2：
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下

示例 3：
输入：m = 7, n = 3
输出：28

示例 4：
输入：m = 3, n = 3
输出：6
*/

/*
机器人从（0，0）位置出发，到（m-1，n-1）终点。
DP五部曲：
    1. 确定dp数组和其下标的含义
        dp[i][j]：从（0，0）出发，到（i，j）位置有dp[i][j]种不同的路径。
    2. 确定递推公式
        想要求dp[i][j]，只有两个方向推导出来，即dp[i-1][j]和dp[i][j-1]。
        此时在回顾一下 dp[i - 1][j] 表示啥，是从(0, 0)的位置到(i - 1, j)有几条路径，dp[i][j - 1]同理。
        那么很自然，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，因为dp[i][j]只有这两个方向过来。
    3. dp数组的初始化
        dp[i][0]一定都是1，因为从（0，0）位置到（i，0）的路径只有一条，那么dp[0][j]也同理。
        所以初始化代码为：
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        其实就是将上边和左边全赋值为1，因为上边只能由前一个推出，左边只能由上一个推出。
    4. 确定遍历顺序
        这里要看一下递归公式dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，dp[i][j]都是
        从其上方和左方推导而来，那么从左到右一层一层遍历就可以了。
        这样就可以保证推导dp[i][j]的时候，dp[i - 1][j] 和 dp[i][j - 1]一定是有数值的。
    5. 举例递推dp数组
        如图：https://img-blog.csdnimg.cn/20201209113631392.png
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));  // 将二维数组初始化为全0
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};