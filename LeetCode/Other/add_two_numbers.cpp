/*
 * @Descripttion: 
 * @Author: AruNi_Lu
 * @Date: 2022-06-17 15:50:44
 */

/*
题目：
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：
输入：
2 ————> 4 ————> 3
5 ————> 6 ————> 4
结果：
7 ————> 0 ————> 8
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

示例 2：
输入：l1 = [0], l2 = [0]
输出：[0]

示例 3：
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
思路：
    1. 同时遍历两个链表，如果有结点为NULL，则将其赋值为0；
    2. 定义一个进位标志flag，默认为0，如果两个结点相加后有进位，则更新进位值；
    3. 每次的数除以10，取余得到该位数，取整得到进位数；
    4. 合并两个链表
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);     // 结果链表虚拟头结点
        ListNode* curNode = dummyNode;        // 链表工作指针，实际上使用此指针去操作dummyNode来保存结果
        int flag = 0;       // 进位
        // 进位不为0，即使l1和l2为空，因为有进位，所以该位的数值不为0
        while (l1 != NULL || l2 != NULL || flag != 0) {
            int num1 = l1 == NULL ? 0 : l1->val;
            int num2 = l2 == NULL ? 0 : l2->val;

            // 如果l1和l2都不为NULL，则需要相加
            int sum = (num1 + num2 + flag) % 10;  // 取得该位的结果值
            flag = (num1 + num2 + flag) / 10;   // 更新进位值

            // 将结果值存储到新结点中
            ListNode* sumNode = new ListNode(sum);

            // 将新节点插入到工作指针的下一个位置（工作指针的头结点是虚拟头结点）
            curNode->next = sumNode;
            curNode = curNode->next;

            // l1和l2指针后移，继续运算下一位
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        // 返回结果链表的头结点
        return dummyNode->next;
    }
};
