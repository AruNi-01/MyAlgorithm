/*
 * @Descripttion: 34.在排序数组中查找元素的第一个和最后一个位置
 * @Author: AruNi
 * @Date: 2022-03-20 18:09:30
 */

/*
题目：
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        if (leftBorder == -2 || rightBorder == -2) {
            return {-1, -1};
        }
        if (rightBorder - leftBorder > 1) {
            return {leftBorder + 1, rightBorder - 1};
        }
        return {-1, -1};
    }

private:
    //寻找左边界
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;    //左边界没有被赋值的情况
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
                leftBorder = right;
            }
        }
        return leftBorder;
    }

    //寻找右边界
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }

};