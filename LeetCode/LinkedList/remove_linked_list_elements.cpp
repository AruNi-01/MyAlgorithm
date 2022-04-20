/*
 * @Descripttion: 203. 移除链表元素
 * @Author: AruNi
 * @Date: 2022-03-27 20:30:05
 */

/*
题目：
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。 
示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]

示例 2：
输入：head = [], val = 1
输出：[]

示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]
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

//为了防止处理头结点和其他节点的方式不一样，可以定义一个虚拟头结点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);       //设置一个虚拟头结点
        dummyHead->next = head;         //将虚拟头结点的next指向head，绑定目标链表
        ListNode* cur = dummyHead;      //cur指针去真正的操作链表
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;     //虚拟头结点的next才是真正的头结点
        delete dummyHead;
        return head;
    }
};