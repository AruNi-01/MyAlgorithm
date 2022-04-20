/*
 * @Descripttion: 面试题 02.07. 链表相交
 * @Author: AruNi
 * @Date: 2022-03-28 12:00:19
 */

/*
题目：
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
示例 1:
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

示例 2:
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Intersected at '2'
解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。
在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*双指针法：需要注意的是，比较的是节点是否相同，不是数值；
           先将两链表的长度做差gap，将较长的链表移动gap个长度，使两链表在同一个起点
           然后将两链表同时往后移动，比较节点是否相等
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL) {      //计算A链表长度
            curA = curA->next;
            lenA++;
        }
        while (curB != NULL) {      //计算B链表长度
            curB = curB->next;
            lenB++;
        }

        //计算完长度将cur链表重新指向各自的头结点，以便后续操作
        curA = headA;       
        curB = headB;

        //指定让curA为较长链表的头结点，lenA为其长度; 若B链表较长，则交换curA和curB；
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;      //长度差

        //让curA和curB在同一起点（末尾位置对齐）
        while (gap--) {
            curA = curA->next;
        }

        //开始往后遍历，遇到相等的结点，直接返回该节点
        while (curA != NULL) {
            if (curA == curB) return curA;

            curA = curA->next;
            curB = curB->next;
        }

        //没有相等的结点返回NULL
        return NULL;
    }
};