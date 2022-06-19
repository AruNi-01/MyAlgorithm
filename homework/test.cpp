/*
 * @Descripttion: 
 * @Author: AruNi_Lu
 * @Date: 2022-04-19 13:27:07
 */
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>


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

	cout << merge.size() << endl;
	for (int i = 0; i < merge.size(); i++) {
		cout << merge[i] << ' ';
	}
	// 求中位数：当merge长度为偶数时，需要取中间两数
	if (merge.size() % 2 == 0) return (merge[merge.size() / 2 - 1] + merge[merge.size() / 2]) / 2.0;
	else return merge[merge.size() / 2];
}

int main() {
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums2.push_back(3);
	nums2.push_back(4);
	double i = findMedianSortedArrays(nums1, nums2);
	cout << i << endl;
	system("pause");
	return 0;
}