/*
 * @Descripttion: 454. 四数相加 II
 * @Author: AruNi
 * @Date: 2022-04-02 21:43:38
 */

/*
题目：
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
    0 <= i, j, k, l < n
    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

示例 1：
输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

示例 2：
输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
*/

//思路：分成两组，将一二数组中各两数之和装进map容器中，key为两数之和，value为次数，
//     再去遍历三四数组，如果map中有值等于0-(c+d)，结果加上map中该value的值(次数)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;       //key：a+b的值；value：a+b值出现的次数
        //先遍历一二数组，统计两数之和和出现的次数
        for (int a : nums1) {
            for (int b : nums2) {
                umap[a + b]++;
            }
        }
        int count = 0;
        //再遍历三四数组，如果map中有值等于0-(c+d)，就把map中key对应的value(次数)统计出来
        for (int c : nums3) {
            for (int d : nums4) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};