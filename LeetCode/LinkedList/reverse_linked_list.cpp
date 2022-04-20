/*
 * @Descripttion: 206. 反转链表
 * @Author: AruNi
 * @Date: 2022-03-27 22:27:36
 */

/*
题目：
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。 

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
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

/*Solution 1: 双指针法
a.首先定义一个cur指针，指向头结点，再定义一个pre指针，初始化为null。
b.然后就要开始反转了，首先要把 cur->next 节点用tmp指针保存一下，也就是保存一下这个节点。
c.为什么要保存一下这个节点呢，因为接下来要改变 cur->next 的指向了，将cur->next 指向pre ，此时已经反转了第一个节点了。
d.接下来，就是循环走如下代码逻辑了，继续移动pre和cur指针。
e.最后，cur 指针已经指向了null，循环结束，链表也反转完毕了。 此时我们return pre指针就可以了，pre指针就指向了新的头结点。
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* temp;
        while (cur) {
            temp = cur->next;     //临时保存该节点的下一个节点，因为马上要反转cur的指向了
            
            cur->next = pre;      //反转curnext的指向
            pre = cur;           //pre等于当前的cur节点
            cur = temp;         //cur继续向后移
        }
        return pre;     //链表反转完后pre就在链表尾部(新的头结点)
};

//Solution 2: 递归法
//和双指针法是一样的逻辑，同样是当cur为空的时候循环结束，不断将cur指向pre的过程。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;

        return reverse(NULL, head);     //调用reverse方法，给pre和cur初始化
    }

    //定义reverse方法用来反转cur的指向，一旦cur为空，就返回pre
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;

        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;

        return reverse(cur, temp);   //此时cur变成了下一次反转指向的pre，temp变成了下一次反转指向的cur
    }
};