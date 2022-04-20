/*
 * @Descripttion: 350. 两个数组的交集 II
 * @Author: AruNi
 * @Date: 2022-03-31 14:06:55
 */

/*
题目：
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，
应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]

示例 2:
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
*/

//双指针法：题目不考虑输出结果的顺序，所以可以将数组先排好序，然后用双指针不断遍历两个数组，发现相同的的就记录
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int index1 = 0;     //index1指向nums1
        int index2 = 0;     //index2指向nums2
        vector<int> result;
        
        //任意一个数组遍历完循环都结束
        while(index1 < nums1.size() && index2 < nums2.size()) {
            //当nums1处的值小于nums2处的值时，index1++；反之index2++；若相等，则说明该数值是交集之一
            if (nums1[index1] < nums2[index2]) {
                index1++;
            } else if (nums1[index1] > nums2[index2]) {
                index2++;
            } else {
                result.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }
        return result;
    }
};