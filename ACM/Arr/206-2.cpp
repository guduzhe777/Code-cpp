/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if((head == NULL)||(head->next == NULL))
        {
            return head; 
        }
        ListNode* new_Node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_Node;        //保存


    // ListNode* next,*prev,*curr;

    // curr = head;    //指向需要修改节点
    // prev = NULL;    //用于指向前一个
    // while(curr){
    //     next = curr->next;
    //     curr->next = prev;
    //     prev = curr;

    //     curr = next;
    // }
    // return prev;
     
    }
};
// @lc code=end

