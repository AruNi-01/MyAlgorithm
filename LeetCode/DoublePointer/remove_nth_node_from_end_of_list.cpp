/*
 * @Descripttion: 19. 删除链表的倒数第 N 个结点
 * @Author: AruNi
 * @Date: 2022-03-28 09:38:05
 */

/*
题目：
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
示例 1:
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]
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

 //双指针法：先让快指针移动n个位置，再让快慢指针一起移动，直到快指针移动到链尾，此时慢指针的next就是要删除的节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while (n-- && fast != NULL) {
            fast = fast->next;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};