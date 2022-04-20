/*
 * @Descripttion: 349. 两个数组的交集
 * @Author: AruNi
 * @Date: 2022-03-31 00:02:59
 */

/*
题目：
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
*/

//思路：输出结果中的每个元素一定是唯一的，也就是说输出的结果的去重的，同时可以不考虑输出结果的顺序，所以可以用unordered_set
//      unordered_set会自动将nums1中的值去重
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;      //存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());        //将nums1转为unordered_set

        //遍历nums2
        for (int num : nums2) {
            //发现nums2的元素在nums_set中也出现过，则满足条件
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }

        //最后将unordered_set转为vector返回
        return vector<int>(result_set.begin(), result_set.end());
    }
};