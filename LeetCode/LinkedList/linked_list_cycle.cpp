/*
 * @Descripttion: 142. 环形链表 II
 * @Author: AruNi
 * @Date: 2022-03-28 12:59:25
 */

/*
题目：给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
双指针法
思路：代码随想录：https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#_142-%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8ii
1.判断链表是否有环: 
可以使用快慢指针法，分别定义 fast 和 slow 指针，从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。
为什么fast 走两个节点，slow走一个节点，有环的话，一定会在环内相遇呢，而不是永远的错开呢？
因为fast是走两步，slow是走一步，其实相对于slow来说，fast是一个节点一个节点的靠近slow的，所以fast一定可以和slow重合。

首先第一点：fast指针一定先进入环中，如果fast指针和slow指针相遇的话，一定是在环中相遇，这是毋庸置疑的。
那么来看一下，为什么fast指针和slow指针一定会相遇呢？
可以画一个环，然后让 fast指针在任意一个节点开始追赶slow指针。
会发现最终都是这种情况， 如图：https://run-notes.oss-cn-beijing.aliyuncs.com/notes/de6628c509b5cdbaa203474e10e3a4fb.gif

2.如果有环，如何找到入口
看图: https://run-notes.oss-cn-beijing.aliyuncs.com/notes/b48c8dceb1d213f05415910247506541.png
这就意味着，从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点。
也就是在相遇节点处，定义一个指针index1，在头结点处定一个指针index2。
让index1和index2同时移动，每次移动一个节点， 那么他们相遇的地方就是 环形入口的节点。
动画如图：https://run-notes.oss-cn-beijing.aliyuncs.com/notes/8f5eae85160e0232dc065af045fbeeb9.gif

那么 n如果大于1是什么情况呢，就是fast指针在环形转n圈之后才遇到 slow指针。
其实这种情况和n为1的时候 效果是一样的，一样可以通过这个方法找到 环形的入口节点，只不过，index1 指针在环里 多转了(n-1)圈，然后再遇到index2，相遇点依然是环形的入口节点。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            //当快慢指针相遇，说明有环，开始找环的入口；
            if (fast == slow) {
                ListNode* index1 = fast;        //index1为相遇结点
                ListNode* index2 = head;        //index2为起始结点
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;      //返回环的入口
            }
        }
        return NULL;
    }
};