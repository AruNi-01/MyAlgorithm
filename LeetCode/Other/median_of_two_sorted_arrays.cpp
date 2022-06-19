/*
 * @Descripttion: 4. 寻找两个正序数组的中位数
 * @Author: AruNi_Lu
 * @Date: 2022-06-19 15:04:40
 */

/*
题目：
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
*/

// 双指针法：两个指针指向两个数组，遍历合并到新数组中，再求中位数。
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> merge;

        // 遍历两个数组，合并到merge数组中
        while ( i < nums1.size() || j < nums2.size()) {
            // 当i和j都指向他们各自的数组时，才作比较
            if (i < nums1.size() && j < nums2.size()) {
                if (nums1[i] < nums2[j]) merge.push_back(nums1[i++]);
                else merge.push_back(nums2[j++]);
            } else {        // 其中一个数组遍历完了，则不能作比较，会越界
                if (i < nums1.size()) merge.push_back(nums1[i++]);
                else merge.push_back(nums2[j++]);
            }
        }

        // 求中位数：当merge长度为偶数时，需要取中间两数
        if (merge.size() % 2 == 0) return (merge[merge.size() / 2 - 1] + merge[merge.size() / 2]) / 2.0;
        else return merge[merge.size() / 2];
    }
};
