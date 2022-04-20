/*
 * @Descripttion: 24. 两两交换链表中的节点
 * @Author: AruNi
 * @Date: 2022-03-27 23:35:18
 */

/*
题目：
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）
示例：
输入：head = [1,2,3,4]
输出：[2,1,4,3]
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

//思路: 正常模拟就OK
//图解过程：https://run-notes.oss-cn-beijing.aliyuncs.com/notes/eeaad8b89896effc1aa2ffa75dd5fe0f.png
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);      //虚拟头结点
        dummyHead->next = head;        //将虚拟头结点的next指向head，绑定目标链表
        ListNode* cur = dummyHead;      //cur指针去真正的操作链表
        while (cur->next != NULL && cur->next->next != NULL) {
            ListNode* temp1 = cur->next;    //记录临时节点1
            ListNode* temp2 = cur->next->next->next;    //记录临时节点3

            //此时链表的指向顺序还没发送变化
            cur->next = cur->next->next;        //1.将虚拟头结点的next指向第2个节点(此时跳过了第1个节点)

            //此时链表的指向顺序已经发送了变化
            cur->next->next = temp1;         //2.相对于原来的链表来说：将第2个节点的next指向第1个节点(此时第1个节点和第2个节点的位置已交换)

            //注意：此时cur->next是第2个节点，cur->next->next是第1个节点
            cur->next->next->next = temp2;      //3.相对于原来的链表来说：将第1个节点的next指向第3个节点(准备开始下一轮交换)

            //将cur向后移2位(相对于原来的链表来说是第1个节点的位置，第1个节点的next就是第3个节点)，继续开始下一轮交换
            cur = cur->next->next;
        }
        return dummyHead->next;     //虚拟头结点的next才是真正的头结点
    }
};