/*
 * @Descripttion: 42. 接雨水
 * @Author: AruNi
 * @Date: 2022-04-07 23:22:33
 */

/*
题目：
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
图示：https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

示例 2：
输入：height = [4,2,0,3,2,5]
输出：9
*/

/*
此题有三种解法：
    双指针法
    动态规划
    单调栈
/*

/*
1.双指针法：按列来计算，宽度固定是1，只需要求出每列的雨水高度
    每一列雨水的高度，取决于该列左侧最高的柱子和右侧最高的柱子中 较矮的那个柱子的高度。然后再用
    此高度减去该列柱子的高度，就是雨水的高度；差值 >0 才记入结果中
注意：第一个柱子和最后一个柱子不接雨水
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            // 第一个和最后一个柱子不接雨水
            if (i == 0 || i == height.size() - 1) continue;

            int rHeight = height[i];  // 记录右边柱子的最高高度
            int lHeight = height[i];  // 记录左边柱子的最高高度
            for (int r = i + 1; r < height.size(); r++) {
                if (height[r] > rHeight) rHeight = height[r];
            }
            for (int l = i - 1; l >= 0; l--) {
                if (height[l] > lHeight) lHeight = height[l];
            }
            int h = min(lHeight, rHeight) - height[i];
            if (h > 0) sum += h;
        }
        return sum;
    }
};
// 因为每次遍历列的时候，还要向两边寻找最高的列，所以时间复杂度为：O(n^2)，LC中可能会超时


/*
2.动态规划DP：
    为了得到两边的最高高度，使用了双指针来遍历，每到一个柱子都向两边遍历一遍，这其实是有重复计算的。
    我们把每一个位置的左边最高高度记录在一个数组上（maxLeft），右边最高高度记录在一个数组上（maxRight）。
    这样就避免了重复计算，这就用到了动态规划。

对当前列来说，左边的最高高度是前一个列的左边最高高度 和 本列高度的最大值；
同理 右边的最高高度是后一个列的右边最高高度 和 本列高度的最大值
即从左向右遍历：maxLeft[i] = max(height[i], maxLeft[i - 1]);
从右向左遍历：maxRight[i] = max(height[i], maxRight[i + 1]);
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int size = height.size();

        // 记录每个柱子左边柱子的最大高度
        maxLeft[0] = height[0];
        for (int i = 1; i < size; i++) {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }

        // 记录每个柱子右边柱子的最大高度
        maxRight[size - 1] = height[size - 1];
        for (int i = size - 2; i >=0; i--) {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }

        // 求和
        int sum = 0;
        for (int i = 0; i < size; i++) {
            int h = min(maxLeft[i], maxRight[i]) - height[i];
            if (h > 0) sum += h;
        }
        return sum;
    }
};
