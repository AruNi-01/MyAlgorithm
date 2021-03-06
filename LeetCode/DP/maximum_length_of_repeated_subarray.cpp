/*
 * @Descripttion: 718. 最长重复子数组
 * @Author: AruNi_Lu
 * @Date: 2022-06-08 15:35:47
 */

/*
题目：
给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。

示例 1：
输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。

示例 2：
输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
*/

/*
注意题目中说的子数组，其实就是连续子序列。这种问题动规最拿手，DP五部曲分析如下：
    1. 确定dp数组和其下标含义
        dp[i][j]：以下标i-1为结尾的A，和以下标j-1结尾的B，最长重复子数组长度为dp[i][j]。
        那dp[0][0]是什么含义呢？总不能是以下标-1为结尾的A数组吧。
        其实dp[i][j]的定义也就决定着，我们在遍历dp[i][j]的时候i 和 j都要从1开始。
        那有疑问了，就定义dp[i][j]为 以下标i为结尾的A，和以下标j 为结尾的B，最长重复子数组长度。不行么？
        行倒是行！ 但实现起来就麻烦一点，大家看下面的dp数组状态图就明白了。
    2. 确定递推数组
        根据dp[i][j]的定义，dp[i][j]的状态只能由dp[i - 1][j - 1]推导出来。
        即当A[i - 1] 和B[j - 1]相等的时候，dp[i][j] = dp[i - 1][j - 1] + 1;
        根据递推公式可以看出，遍历i 和 j 要从1开始！
    3. dp数组的初始化
        根据dp[i][j]的定义，dp[i][0] 和dp[0][j]其实都是没有意义的！
        但dp[i][0] 和dp[0][j]要初始值，因为 为了方便递归公式dp[i][j] = dp[i - 1][j - 1] + 1;
        所以dp[i][0] 和dp[0][j]初始化为0。
        举个例子A[0]如果和B[0]相同的话，dp[1][1] = dp[0][0] + 1，只有dp[0][0]初始为0，正好符合递推公式逐步累加起来。
    4. 确定遍历顺序
        外层for循环遍历A，内层for循环遍历B。
        那又有疑问了，外层for循环遍历B，内层for循环遍历A。不行么？
        也行，一样的，这里就用外层for循环遍历A，内层for循环遍历B了。
        同时题目要求长度最长的子数组的长度。所以在遍历的时候顺便把dp[i][j]的最大值记录下来。
        代码如下：
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result) result = dp[i][j];
            }
        }
    5. 举例推导dp数组
        拿示例1中，A: [1,2,3,2,1]，B: [3,2,1,4,7]为例，画一个dp数组的状态变化，如下：
        https://img-blog.csdnimg.cn/2021011215282060.jpg
*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};